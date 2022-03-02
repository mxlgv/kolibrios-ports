CC = i686-w64-mingw32-gcc
LD = i686-w64-mingw32-ld

INCLUDES =      -I../include \
                -I../include/asm   \
                -I../include/uapi  \

DEFINES =  -DKOLIBRI -D__KERNEL__ -DCONFIG_X86_32 -DCONFIG_DMI -DCONFIG_TINY_RCU
DEFINES += -DCONFIG_X86_L1_CACHE_SHIFT=6 -DCONFIG_ARCH_HAS_CACHE_LINE_SIZE
DEFINES += -DCONFIG_PRINTK -DCONFIG_AMD_NB

CFLAGS = -c -Os $(INCLUDES) $(DEFINES) -march=i686 -fomit-frame-pointer -fno-builtin-printf -mno-stack-arg-probe  -fno-ident -mpreferred-stack-boundary=2 -mincoming-stack-boundary=2 -mno-ms-bitfields



LIN_OBJS:= \
        debug/dbglog.o    \
        debug/chkstk.o    \
        dma/dma_alloc.o   \
        dma/fence.o       \
        io/create.o       \
        io/finfo.o        \
        io/ssize.o        \
        io/write.o        \
        linux/bitmap.o    \
        linux/ctype.o     \
        linux/div64.o     \
        linux/dmapool.o   \
        linux/dmi.o       \
        linux/fbsysfs.o   \
        linux/find_next_bit.o \
        linux/firmware.o  \
        linux/gcd.o       \
        linux/hdmi.o      \
        linux/hexdump.o   \
        linux/idr.o       \
        linux/interval_tree.o \
        linux/kasprintf.o \
        linux/kmap.o      \
        linux/list_sort.o \
        linux/mutex.o     \
        linux/rbtree.o    \
        linux/scatterlist.o \
        linux/string.o    \
        linux/time.o      \
        linux/workqueue.o \
        linux/msr.o       \
        linux/amd_nb.o    \
        linux/cpu_detect.o \
        malloc/malloc.o   \
        stdio/vsprintf.o  \
        string/strstr.o   \
        string/_memmove.o \
        string/_strncat.o \
        string/_strncmp.o \
        string/_strncpy.o \
        string/_strnlen.o \
        string/bcmp.o     \
        string/bcopy.o    \
        string/bzero.o    \
        string/index.o    \
        string/memchr.o   \
        string/memcmp.o   \
        string/memcpy.o   \
        string/memmove.o  \
        string/memset.o   \
        string/rindex.o   \
        string/strcat.o   \
        string/strchr.o   \
        string/strcmp.o   \
        string/strcpy.o   \
        string/strlen.o   \
        string/strncat.o  \
        string/strncmp.o  \
        string/strncpy.o  \
        string/strnlen.o  \
        string/strrchr.o

CORE_OBJ = core.o

LIBLINUX = liblinux3.a
LIBCORE  = libcore.a

all: $(LIBCORE) $(LIBLINUX)

$(LIBLINUX): $(LIN_OBJS) Makefile
	$(AR) cvrs $@ $(LIN_OBJS)

$(LIBCORE):  $(CORE_OBJ) Makefile
	$(LD) -shared -s --out-implib $@ -o core.dll $(CORE_OBJ)

%.o: %.S Makefile
	$(CC) $(CFLAGS) -o $@ $<

%.o: %.c Makefile $(INCLUDES)
	$(CC) $(CFLAGS) -o $@ $<

clean: 
	rm -f $(LIBCORE) $(LIBLINUX) $(CORE_OBJ) $(LIN_OBJS)
