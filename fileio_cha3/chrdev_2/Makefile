ifeq ($(KERNELRELEASE),)
 
KERNELDIR ?= /usr/src/linux-headers-2.6.35-22-generic/
PWD := $(shell pwd)
 
.PHONY: modules modules_install clean disclean

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
 
modules_install:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install
 
clean:
	rm -rf *.o *~ core .depend  *.order  *.mod.c .tmp_versions *.symvers ko*
	rm -rf a.out 
disclean:
	rm -rf *ko


else
   obj-m += devmodule.o
endif
