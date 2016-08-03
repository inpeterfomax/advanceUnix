#include "transceiver.h"

static int local_open(struct inode *node,struct file*filp)
{
	return 0;
}

static void local_release(struct inode *node,struct file*filp)
{
}

static void local_ioctl(struct inode *node,struct file *filp,
		 unsigned int ioctl_num,unsigned long ioctl_param)
{
}

static void local_mmap(struct file *filp, struct vm_area_struct *vma){

}

