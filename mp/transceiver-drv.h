#ifndef _TRANSCEIVER_H_
#define _TRANSCEIVER_H_

struct local_ts_dev{
	cdev dev;
};

static int local_open(struct inode *, struct file *);
static void local_release(struct inode *, struct file *);
static void local_ioctl(struct inode *,struct file *,
		 unsigned int ,unsigned long );
static void local_mmap(struct file *,struct vm_area_struct *);


#endif
