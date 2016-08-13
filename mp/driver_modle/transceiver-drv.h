#ifndef _TRANSCEIVER_H_
#define _TRANSCEIVER_H_

#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/device.h>

#include <net/netlink.h>

#include <linux/slab.h>	//for kmalloc

struct local_dev{
	struct cdev *cdev;
};

static int local_open(struct inode *, struct file *);
static int local_release(struct inode *, struct file *);
static int local_ioctl(struct inode *,struct file *,
		 unsigned int ,unsigned long );
static int local_mmap(struct file *,struct vm_area_struct *);



static int local_open(struct inode *node,struct file*filp)
{
	printk("%s %d\n",__FUNCTION__,__LINE__);
	return 0;
}

static int local_release(struct inode *node,struct file*filp)
{
	printk("%s %d\n",__FUNCTION__,__LINE__);
	return 0;
}

static int local_ioctl(struct inode *node,struct file *filp,
		 unsigned int ioctl_num,unsigned long ioctl_param)
{
	//char arry[128]={0};
	//copy_from_user(arry,ioctl_param);
	switch(ioctl_num){
		case 0:
			break;
		case 1:
			break;
		default:
			break;
	}
	
	return 0;
}

static int local_mmap(struct file *filp, struct vm_area_struct *vma)
{
	return 0;
}

#endif
