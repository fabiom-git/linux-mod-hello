#~ Makefile to make modules under linux
#~ - from the book 'Linux Device Drivers'
#~ 
#~ FabioMesiti-2013
#~ 

# Uncomment the following to enable debug.
#~ DEBUG = y
#~ 
#~ ifeq ($(DEBUG),y)
	#~ DBGFLAGS = -O -g -DML_DEBUG
#~ else
	#~ DBGFLAGS = -O2
#~ endif

#CFLAGS += $(DBGFLAGS)


ifneq ($(KERNELRELEASE),)
	obj-m := mod_hello.o
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
	rm *.symvers
	
endif
