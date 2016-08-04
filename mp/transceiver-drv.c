/*
* name: transceiver-drv.c.
* author:peter_gu@realsil.com.cn.
* function:cmd interrupt handler and response sender.
* version:v1.0
*/

#include "transceiver-drv.h"

#define SUCCESS 0
#define DEVICE_NAME "transceiver" /* Dev name as it appears in /proc/devices   */
#define CLASS_NAME "transceiver-class"
#define BUF_LEN 80            /* Max length of the message from the device */

//#define IRQNUM gpio_irq

static int major,minor;      /* Major,Minor number assigned to our device driver */
static int device_open = 0;  /* Is device open?  Used to prevent multiple
                                        access to the device */
static unsigned int mycdevnum = 0;	 /* Transciver dev number,major & minor*/
static char msg[BUF_LEN];    /* The msg the device will give when asked    */
static char *msg_Ptr;

struct local_dev *mydev=NULL;


static struct class *tranceiver_class;
static struct device *tranceiver_dev; 

static int local_open(struct inode *node,struct file*filp)
{
	return 0;
}

static int local_release(struct inode *node,struct file*filp)
{
	return 0;
}

static int local_ioctl(struct inode *node,struct file *filp,
		 unsigned int ioctl_num,unsigned long ioctl_param)
{
	return 0;
}

static int local_mmap(struct file *filp, struct vm_area_struct *vma)
{
	return 0;
}

static const struct file_operations transceiver_ops={
	.owner = THIS_MODULE,
	.open = local_open,
	.release = local_release,
	.ioctl = local_ioctl,
	.mmap = local_mmap,
};

/* Declare the sysfs entries. The macros create instances of dev_attr_fifo and dev_attr_reset */
/* device attributes file.Just incase.*/
static ssize_t show_opt(struct device *dev,struct device_attribute *attr,char *buf)
{
	return 0;
}
static ssize_t store_opt(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
	return 0;
}

static struct device_attribute local_dev_attr = {
	.attr = {
		.name = "transciver-attr",
		.mode = S_IWUSR | S_IRUGO,
	},
	.show = show_opt,
	.store = store_opt,
};

static struct device_attribute device_attrs[]={
	&local_dev_attr,
	NULL,
};

irq_handler cmd_handler(){
	clean_irq_state(s);
	disable_irq();

	/*send cmd msg to mpv50 */
	cmdmsg = alloc_msg;
	send_cmd_to_mpv50;
	sendmsg(cmdmsg);

	/*wait for response msg from mpv50*/
	write_resp_to_register();
}

static __init int transceiver_init(void)
{
	int retval,i;
	mydev =(struct local_dev *) kmalloc(sizeof(struct local_dev),GFP_KERNEL);
	if(!mydev){
		printk("%s %d kmalloc fail\n",__FUNCTION__,__LINE__);
		return -1;
	}
	retval = alloc_chrdev_region(&mycdevnum,0,1,DEVICE_NAME);
	if(retval < 0){
		printk("%s %d , alloc fail\n",__FUNCTION__,__LINE__);
		goto alloc_fail;
	}
	major = MAJOR(mycdevnum);

	cdev_init(&mydev->cdev,&transceiver_ops);
	mydev->cdev.owner = THIS_MODULE;
	mydev->cdev.ops = &transceiver_ops;
	retval = cdev_add(&mydev->cdev,mycdevnum,1);
	if( retval ){
		printk("%s %d , retval=%d \n",__FUNCTION__,__LINE__,retval);
		goto class_fail;
	}
	
	tranceiver_class = class_create(THIS_MODULE,CLASS_NAME);
	if( IS_ERR(tranceiver_class) ){
		retval =  PTR_ERR(tranceiver_class);
		goto class_fail;
	}
	/* With a class, the easiest way to instantiate a device is to call device_create() . Creat /dev/device */
 	tranceiver_dev = device_create(tranceiver_class, NULL, mycdevnum, NULL, CLASS_NAME "_" DEVICE_NAME);
	if (IS_ERR(tranceiver_dev)) {
		printk("failed to create device '%s_%s'\n", CLASS_NAME, DEVICE_NAME);
	    retval = PTR_ERR(tranceiver_dev);
	    goto failed_devreg;
	  }
	/*Create attribute files*/
	for (i = 0; i < ARRAY_SIZE(device_attrs); i++) {
		retval = device_create_file(tranceiver_dev, &device_attrs[i]);
		if (retval)
			break;
	}
	if (retval) {
		while (--i >= 0)
			device_remove_file(tranceiver_dev, &device_attrs[i]);
	}

	/*alloc irq for cmd done*/
	retval = request_irq(gpio_to_irq(gpio),handler,flag,device);

	
	return 0;
	
failed_devreg:
	class_destroy(tranceiver_class);
	return retval;
class_fail:
	unregister_chrdev_region(mycdevnum,DEVICE_NAME);
	return -1;
register_fail:
	return retval;

alloc_fail:
	return retval;
	
}
static __exit void transceiver_clean(void)
{
	int i;
		
	/*Remove attribute files*/
	for (i = 0; i < ARRAY_SIZE(device_attrs); i++) {
		device_remove_file(tranceiver_dev, &device_attrs[i]);
	}
	device_destroy(tranceiver_class, mycdevnum);
	class_destroy(tranceiver_class);
	unregister_chrdev(major, DEVICE_NAME);
	/*free mydev struct.*/
	if( mydev )
		kfree(mydev);
}



module_init(transceiver_init);
module_exit(transceiver_clean);

#define DESCRIPTION "create an vitrual cdev, \
					it takes responsibility to handle gpio interrupt \
					then send cmd to mpv50 process \
					and receive msg form mpv50 then write back response \
					to resp-register."

MODULE_LICENSE("GPL");
MODULE_AUTHOR("peter_gu@realsil.com.cn");
MODULE_DESCRIPTION(DESCRIPTION);
