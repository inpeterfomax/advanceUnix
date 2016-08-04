ifneq ( $(KERNELRELEASE), )
	obj-m :=  transceiver-drv.o 
	transceiver-drv-objs := transceiver-drv.o transceiver-func.o
else
	KERNELDIR ?= /home/peter/raw/Project_88EE_8723D/SDK/rlxlinux-sdk321-v50/linux-2.6.30/
	PWD := $(shell pwd)
	
default:
#	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	make ARCH=rlx CROSS_COMPILE=/home/peter/raw/Project_88EE_8723D/SDK/rlxlinux-sdk321-v50/toolchain/rsdk-1.5.5-5281-EB-2.6.30-0.9.30.3-110714/bin/rsdk-linux- -C $(KERNELDIR) M=$(PWD) modules

endif

.PHNHY:clean
clean:
	rm -rf *.o *.ko *~ core .depend *.mod.c .*.cmd .tmp_versions .*.o.d

