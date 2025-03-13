TOOLCHAIN := /usr/bin/arm-linux-gnueabihf-gcc

ifeq ($(ARCH), arm) 
	CC := $(TOOLCHAIN)
endif

all:
	$(CC) -o hello hello.c
clean:
	rm -rf hello