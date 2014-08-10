/*
Name       :devmodule.c
Discription:linux char driver test
Date       :2013-06-18 
Author     :
*/

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <asm/irq.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/ioctl.h>
#include <asm/uaccess.h>
#include <linux/fs.h> 
#include <linux/kobject.h> 
#include <linux/slab.h>
#include "command.h"

#define DEVICE_NAME "TestDev" 
#define CLASS_NAME "TestDevClass" 
#define SYSPATH		"/tmp/myfile"

char buff[16] = {'0'};

int dev_major =0;
int dev_minor =0;
/*pass the parameters when insmod the driver.*/
module_param(dev_major,int,0644);
module_param(dev_minor,int,0644);

int read_file_kernelspace(char*path,char*buff,int size)
{
	struct file *fptr =NULL;
	mm_segment_t old_addr;
	old_addr = get_fs();
	set_fs(KERNEL_DS);
	
	printk("before filp_open(path,O_RDONLY,0)\n");

	fptr = filp_open(path,O_RDONLY,0);
	if( fptr == NULL)
	{
		printk("filp_open failed\n");
		return -1;
	}

	int readLen = fptr->f_op->read(fptr,buff, size, &fptr->f_pos);

	if ( readLen != size)
	{

		printk("readLen != size,anyway:");
		printk("buff:%s\n",buff);
	
		filp_close(fptr,NULL);
		set_fs(old_addr);
		
		return -1;
	}

	filp_close(fptr,NULL);
	set_fs(old_addr);
	
	printk("buff:%s\n",buff);

	return 0;
}

int write_file_kernelspace(char*path,char*buff,int size)
{
	struct file *fptr =NULL;
	mm_segment_t old_addr;
	old_addr = get_fs();
	set_fs(KERNEL_DS);
	
	printk("before filp_open(SYSPATH,O_WRONLY,0)\n");
	fptr = filp_open(SYSPATH,O_WRONLY|O_CREAT,0644);
	if( NULL == fptr )
	{
		printk("filp_open failed\n");
		return -1;
	}
	printk("after filp_open(SYSPATH,O_WRONLY,0)\n");
	
	printk("before writeLen = fptr->f_op->write(fptr,buff,size,&fptr->f_pos)\n");
	int writeLen = fptr->f_op->write(fptr,buff,size,&fptr->f_pos);				//problem? Ð´È¨ÏÞ 
	printk("after writeLen = fptr->f_op->write(fptr,buff,size,&fptr->f_pos)\n");
	
	if ( writeLen != size)
		printk("writeLen != size,anyway:writeLen:%d\n",writeLen);

	filp_close(fptr,NULL);
	set_fs(old_addr);

	return 0;
}

static int open_test(struct inode *inode, struct file *file)
{
	struct file *fileptr;
	mm_segment_t old_addr = get_fs(); //get the current address the process can access.
	char buf[16]={'\0'};
	int len = 16;
	int retlen=0;

	set_fs(KERNEL_DS);
	
	fileptr = filp_open("./test.txt",O_RDWR|O_CREAT,0644);
	
	if(IS_ERR(fileptr)){
		printk("filp_open :failed to open\n");
		return -1;
	}
	do{
		if((fileptr->f_op == NULL) || (fileptr->f_op->read == NULL))
		{
			printk("file coule not read\n");
			break;
		}else{
			fileptr->f_pos = 0;
		}
		retlen = fileptr->f_op->read(fileptr,buf,len,&fileptr->f_pos);
	}while(false);

	filp_close(fileptr,NULL);

	set_fs(old_addr);
	
	printk("read from user space file ./test.txt %s:\n",buf);
	
	return 0;
}

static int close_test(struct inode *inode, struct file *file)
{
	return 0;
}

static int ioctl_test( struct inode *inode, struct file *file, unsigned int cmd, void *arg)
{
	int data=16;
	bool err=0;
	
	if(_IOC_TYPE(cmd) != TESTMAGIC)
		return -ENOTTY;
	if(_IOC_NR(cmd) > MAX_CMD_NUM) 
		return -ENOTTY;	
	
	if(_IOC_DIR(cmd) & _IOC_READ)
		err = !access_ok(VERIFY_WRITE,(void __user*)arg , _IOC_SIZE(cmd));
	else if(_IOC_DIR(cmd) & _IOC_WRITE)
		err = !access_ok(VERIFY_READ,(void __user*)arg , _IOC_SIZE(cmd));
	if (err)
		return -EFAULT; 

	printk("%s(): cmd=%s, arg=%d\n", __func__, (cmd==GET_TEST)?"get":"set", arg);
	//dump_stack();

	switch(cmd)
	{
		case GET_TEST:
			put_user(data,(int __user*)arg);
			write_file_kernelspace(SYSPATH,"hello\\n",6);
		case SET_TEST:
			get_user(data,(int __user*)arg);
			printk("data:%d\n",data);
			break;
		default:
			break;
	}
	
	return 0;
}
static ssize_t write_test(struct file* pfile,const char * buf , size_t size , loff_t * offset){

	return 0;
}
static ssize_t read_test(struct file* pfile, char  * buf, size_t size , loff_t * offset){

	return 0;
}

struct file_operations test_ops = {
	.owner   = THIS_MODULE,
	.open    = open_test,
	.release = close_test,
	.ioctl   = ioctl_test,
	.read	 = read_test,
	.write   = write_test,
};

struct cdev *test_cdev; 
struct device *cdev_device;
struct class *cdev_class;
dev_t devid;  
struct kobject *cdev_kobject;
 
/*this file-attribute*/
	struct device_attribute attrs []= {
	{
		.attr = {
			.owner = THIS_MODULE,
			.name = "TestDev_attr_name",
			.mode =  S_IRWXU | S_IRWXG | S_IRWO,
		},
			.show  = testdev_show,
			.store = testdev_store,
		},
	};

static int cdev_create_function_files(struct device *cdev_device){
	int i,ret;
	for(i=0,i<ARRY_SIZE(attrs),i++){
		ret = device_create_file(cdev_device,&attrs[i]);
		if(ret){
			printk("create attribute failed\n");
			device_remove_file(cdev_device,&attrs[i]);
			exit(-1);
		}
	}
}

static ssize_t testdev_show(struct device *dev,char*buff){
	printk("this is the show function!\n");
	return sprintf(buff,"thie state of the driver is %s","what is the func????");

}
static ssize_t testdev_store(struct device *dev,const char*buff, int len){
	printk("i get this string :%s from userspace!\n",buff);
}


static int __init test_init(void)
{
	int ret;

	if(dev_major){    						//pase a parameter when insmod the module
		devid = MKDEV(dev_major,dev_minor);
		ret = register_chrdev_region(devid,0,DEVICE_NAME);
		if (ret < 0){
			printk( KERN_ERR" can't register major number\n");
			return ret;
		}
	}else{
		ret = alloc_chrdev_region(&devid,0,1,DEVICE_NAME);
		if(ret < 0){
			printk(KERN_ERR"alloc failed\n");
			return -1;
		}
		dev_major = MAJOR(devid);
	} 
	
	/*
	cdev_kobject = (struct kobject *)kzalloc(sizeof(struct kobject),GFP_KERNEL);
	if(cdev_kobject == NULL)
	{
		printk("kzalloc failed!\n");
		return -1;
	}
	kobject_init(cdev_kobject,NULL);
	kobject_put(cdev_kobject);     //set the reference to be zero;
	ret = kobject_set_name(cdev_kobject,"Test_dev kobject");
	if(ret < 0){
		printk("kobject_set_name faied!\n"); 
		return -2;
	}
	kobject_add(cdev_kobject,NULL); 
	*/
	cdev_kobject = kobject_create_and_add("Cdev_Kobject",NULL);
	test_cdev->kobj = *cdev_kobject;  //does this work?

	if( (test_cdev = cdev_alloc()) == NULL ){
		printk(KERN_ERR"alloc_cdev failed!\n");
		return -1;
	}

	/*do somethins initialization things*/
	cdev_init(test_cdev,&test_ops);
	test_cdev->owner=THIS_MODULE;
	
	if( cdev_add(test_cdev,devid,1) !=  0){ unregister_chrdev_region(devid,1);
		printk(KERN_ERR"cdev_add failed!\n");
		return -1;
	} 
	/*if(	(ret = register_chrdev(dev_major,DEVICE_NAME,&test_ops)) != 0){
		printk("register_chrdev failed!\n");
		return ret;
	}*/

	cdev_class = class_create(THIS_MODULE, CLASS_NAME);
	if(IS_ERR(cdev_class)){
		cdev_del(test_cdev);
		unregister_chrdev_region(devid,1);
		printk("Err: failed in class_create. \n");
		return -1;
	}
	cdev_device = device_create(cdev_class, NULL, devid, NULL, DEVICE_NAME); //this function is very important;
	if(IS_ERR(cdev_device)){
		class_destroy(cdev_class);
		cdev_del(test_cdev);
		unregister_chrdev_region(devid,1);
		printk("Err: failed in class_create. \n");
		return -1;
	}
	printk(DEVICE_NAME " initialized\n");
	
	cdev_create_function_files(cdev_device);

	return 0;
}

static void __exit test_exit(void)
{
	kobject_put(cdev_kobject);
	device_destroy(cdev_class,devid);  //parameter 1 is very important!
	class_destroy(cdev_class);
	unregister_chrdev(dev_major,DEVICE_NAME);
	unregister_chrdev_region(devid,1);
}

module_init(test_init);
module_exit(test_exit);

MODULE_AUTHOR("peter.gu");
MODULE_DESCRIPTION("for test");
MODULE_LICENSE("GPL");
