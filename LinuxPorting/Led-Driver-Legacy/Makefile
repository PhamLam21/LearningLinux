TOOLCHAIN := /home/phamlam21/ws/BBB/gcc-linaro-6.5.0-2018.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-

EXTRA_CFLAGS = -Wall
obj-m = LedDriver.o
C_FLAGS := -c -fPIC -o

KDIR := /home/phamlam21/ws/BBB/kernelbuildscripts/KERNEL

all:
#$(TOOLCHAIN) $(C_FLAGS) ./LedDriver.o ./LedDriver.c -I ./
	$(MAKE) -C $(KDIR) M=`pwd` ARCH=arm CROSS_COMPILE=$(TOOLCHAIN) modules
clean:
	$(MAKE) -C $(KDIR) M=`pwd` clean
