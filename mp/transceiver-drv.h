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
	struct cdev cdev;
};

static int local_open(struct inode *, struct file *);
static int local_release(struct inode *, struct file *);
static int local_ioctl(struct inode *,struct file *,
		 unsigned int ,unsigned long );
static int local_mmap(struct file *,struct vm_area_struct *);


#endif
