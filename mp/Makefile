export DIR_LINUX= /home/peter/raw/Project_88EE_8723D/SDK/rlxlinux-sdk321-v50/linux-2.6.30
EXTRA_CFLAGS += -DCONFIG_BIG_ENDIAN -DMP_V50_PLATFORM -DMP_V50_88EE_8723D_SUPPORT
ARCH := rlx
CROSS_COMPILE:= $(DIR_LINUX)/../toolchain/rsdk-1.5.5-5281-EB-2.6.30-0.9.30.3-110714/bin/rsdk-linux-
KSRC := $(DIR_LINUX)

CC := $(CROSS_COMPILE)gcc

ifneq ($(KERNELRELEASE),)
	#obj-m :=  transceiver-drv.o 
	obj-m := transceiver.o
	transceiver-objs := transceiver-drv.o transceiver-func.o
else
	PWD := $(shell pwd)

all : modules mpv50
modules:
	$(MAKE) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KSRC) M=$(PWD)  modules

mpv50.o:mpv50.c
	$(CC) -c mpv50.c
mpv50:mpv50.o
	$(CC) -o mpv50.o

.PHNHY: modules clean

clean:
	rm *.out 
	rm -rf *.o *.ko *~ core .depend *.mod.c .*.cmd .tmp_versions .*.o.d *.order *.symvers
	
endif

