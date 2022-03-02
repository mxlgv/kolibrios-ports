CC = i686-w64-mingw32-gcc
LD = i686-w64-mingw32-ld
KPACK = kpack

DRV_INCLUDES    = ../../liblinux3/include

INCLUDES = -I$(DRV_INCLUDES) \
           -I$(DRV_INCLUDES)/asm  \
           -I$(DRV_INCLUDES)/uapi \
           -I$(DRV_INCLUDES)/drm

NAME= k10temp

DEFINES = -DKOLIBRI -D__KERNEL__ -DCONFIG_X86_32 -DCONFIG_DMI -DCONFIG_TINY_RCU
DEFINES+= -DCONFIG_X86_L1_CACHE_SHIFT=6 -DCONFIG_ARCH_HAS_CACHE_LINE_SIZE
DEFINES+= -DCONFIG_PRINTK -DCONFIG_PCI -DCONFIG_PCI  -DCONFIG_AMD_NB -DKBUILD_MODNAME=\"k10temp\"

CFLAGS= -c -Os -march=i686 -fno-ident -msse2 -mno-stack-arg-probe -fno-ident -mpreferred-stack-boundary=2 -mincoming-stack-boundary=2 -mno-ms-bitfields

LIBPATH = -L ../../liblinux3/src

LIBS:=    -llinux3 -lcore

LDFLAGS = -nostdlib -shared -s --major-os-version 0 --minor-os-version 7 \
	--major-subsystem-version 0 --minor-subsystem-version 5 --subsystem native \
	--image-base 0 --file-alignment 512 --section-alignment 4096 -T ../../drv.lds


OBJS = k10temp.o pci.o

all: $(OBJS) $(NAME).sys 

$(NAME).sys: $(OBJS) 
	$(LD) $(LIBPATH) $(LDFLAGS)  $(OBJS) -o $@ $(NAME_OBJS) $(LIBS)
	$(KPACK) $(NAME).sys

%.o : %.c Makefile
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -o $@ $<  

clean:
	rm -f $(OBJS) $(NAME).sys
