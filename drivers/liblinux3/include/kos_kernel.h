#ifndef _KOS_KERNEL_H_
#define _KOS_KERNEL_H_

#include <stddef.h>

extern void *memset (void *destination, int c, size_t n);

#ifndef __import 
#define __import   __attribute__ ((dllimport))
#endif

#ifndef __stdcall 
#define __stdcall  __attribute__ ((stdcall))
#endif

#ifndef __fastcall
#define __fastcall __attribute__ ((fastcall))
#endif

#define __stdcall_imp  __stdcall __import
#define __fastcall_imp __fastcall __import

#define KOS_BASE 0x80000000


#define _alloca(x) __builtin_alloca((x))

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

#pragma pack(push, 1)

typedef struct {
  u32        handle;
  u32        io_code;
  void       *input;
  int        inp_size;
  void       *output;
  int        out_size;
} kos_ioctl_t;
  
struct kos_pdev {
    struct kos_pdev *prev;
    struct kos_pdev *next;
    u32 devid;
    u32 class_d;
    u8  devfn;
    u8  bus;
    u8  _reserved[2];
    u32 owner;
};

typedef struct {
    u32 p00;
    union {
        u64 p04;
        struct {
            u32 p04dw;
            u32 p08dw;
        };
    };
    u32 p12;
    union {
        u32         p16;
        const char *new_name;
        void        *bdfe;
        void        *buf16;
        const void  *cbuf16;
    };
    char p20;
    const char *p21;
} kos_fs_t;

typedef union {
	struct {
		u32 handle;
		u32 euid;
	};
	u64 raw;
} evhandle_t;

typedef struct {
	u32  code;
	u32  data[5];
} kevent_t;

struct kos_taskdata
{
    u32 event_mask;
    u32 pid;
    u16 r0;
    u8  state;
    u8  r1;
    u16 r2;
    u8  wnd_number;
    u8  r3;
    u32 mem_start;
    u32 counter_sum;
    u32 counter_add;
    u32 cpu_usage;
};

#pragma pack(pop)

enum KOS_PG {
    KOS_PG_SW  = 0x003,
    KOS_PG_UW  = 0x007,
    PG_WRITEC  = 0x008,
    PG_NOCACHE = 0x018,
    PG_SHARED  = 0x200
};

typedef int (__stdcall *kos_srv_proc_t)(kos_ioctl_t *);

u32 drvEntry(int, char *) __asm__("_drvEntry");

void* __stdcall_imp kos_alloc_kern_space(size_t size)                           __asm__("AllocKernelSpace");
void  __stdcall_imp kos_free_kern_space(void *mem)                              __asm__("FreeKernelSpace");
u32   __stdcall_imp kos_map_io_mem(u32 base, size_t size, u32 flags)            __asm__("MapIoMem");
void* __stdcall_imp kos_kern_alloc(size_t size)                                 __asm__("KernelAlloc");
void* __stdcall_imp kos_kern_free(const void *mem)                              __asm__("KernelFree");
void* __stdcall_imp kos_user_alloc(size_t size)                                 __asm__("UserAlloc");
int   __stdcall_imp kos_user_free(void *mem)                                    __asm__("UserFree");

void* __stdcall_imp kos_get_display(void)                                       __asm__("GetDisplay");

u32   __import  kos_get_timer_ticks(void)                                       __asm__("GetTimerTicks");
u64   __import  kos_get_clock_ns(void)                                          __asm__("GetClockNs");

u32   __stdcall_imp kos_alloc_page(void)                                        __asm__("AllocPage");
u32   __stdcall_imp kos_alloc_pages(u32 count)                                  __asm__("AllocPages");
void  __import  __attribute__((regparm(1))) kos_free_page(u32 page)             __asm__("FreePage");
void  __stdcall_imp kos_map_page(void *vaddr, u32 paddr, u32 flags)             __asm__("MapPage");


void* __stdcall_imp kos_create_ring_buffer(size_t size, u32 map)                __asm__("CreateRingBuffer");

u32   __stdcall_imp kos_reg_service(char *name, kos_srv_proc_t proc)            __asm__("RegService");

int   __stdcall_imp kos_attach_int_handler(int irq, void *handler, u32 access)  __asm__("AttachIntHandler");

void  __fastcall_imp kos_mutex_init(void* mutex)                                __asm__("MutexInit");
void  __fastcall_imp kos_mutex_lock(void* mutex)                                __asm__("MutexLock");
void  __fastcall_imp kos_mutex_unlock(void* mutex)                              __asm__("MutexUnlock");

void  __fastcall_imp kos_init_rw_sem(void* sem)                                 __asm__("InitRwsem");
void  __fastcall_imp kos_down_read(void* sem)                                   __asm__("DownRead");
void  __fastcall_imp kos_down_write(void* sem)                                  __asm__("DownWrite");
void  __fastcall_imp kos_up_read(void* sem)                                     __asm__("UpRead");
void  __fastcall_imp kos_up_write(void* sem)                                    __asm__("UpWrite");

u32 __import  kos_get_stack_base(void)                                          __asm__("GetStackBase");
u32 __import  kos_get_pid(void)                                                 __asm__("GetPid");

u32  __stdcall_imp kos_timer_hs(u32 delay, u32 interval, void *fn, void *data)  __asm__("TimerHS");
void __stdcall_imp kos_cancel_timer_hs(u32 handle)                              __asm__("CancelTimerHS");

u64 __import kos_get_cpu_freq(void)                                             __asm__("GetCpuFreq");

void __stdcall_imp  kos_set_mouse_data(int btn, int x, int y, int z, int h)     __asm__("SetMouseData");
void __fastcall_imp kos_set_keyboard_data(u32 data)                             __asm__("SetKeyboardData");

struct kos_pdev* __import kos_get_pci_list(void)                                __asm__("GetPCIList");

u8  __stdcall_imp kos_pci_read8(u32 bus, u32 devfn, u32 reg)                    __asm__("PciRead8");
u16 __stdcall_imp kos_pci_read16(u32 bus, u32 devfn, u32 reg)                   __asm__("PciRead16");
u32 __stdcall_imp kos_pci_read32(u32 bus, u32 devfn, u32 reg)                   __asm__("PciRead32");

u32 __stdcall_imp kos_pci_write8(u32 bus, u32 devfn, u32 reg, u8 val)           __asm__("PciWrite8");
u32 __stdcall_imp kos_pci_write16(u32 bus, u32 devfn, u32 reg, u16 val)         __asm__("PciWrite16");
u32 __stdcall_imp kos_pci_write32(u32 bus, u32 devfn, u32 reg,u32 val)          __asm__("PciWrite32");

#define kos_pci_read_byte(tag, reg) \
        kos_pci_read8(PCI_BUS_FROM_TAG(tag),PCI_DFN_FROM_TAG(tag),(reg))

#define kos_pci_read_word(tag, reg) \
        kos_pci_read16(PCI_BUS_FROM_TAG(tag),PCI_DFN_FROM_TAG(tag),(reg))

#define kos_pci_read_dword(tag, reg) \
        kos_pci_read32(PCI_BUS_FROM_TAG(tag),PCI_DFN_FROM_TAG(tag),(reg))

#define kos_pci_write_byte(tag, reg, val) \
        kos_pci_write8(PCI_BUS_FROM_TAG(tag),PCI_DFN_FROM_TAG(tag),(reg),(val))

#define kos_pci_write_word(tag, reg, val) \
        kos_pci_write16(PCI_BUS_FROM_TAG(tag),PCI_DFN_FROM_TAG(tag),(reg),(val))

#define kos_pci_write_dword(tag, reg, val) \
        kos_pci_write32(PCI_BUS_FROM_TAG(tag),PCI_DFN_FROM_TAG(tag),(reg),(val))

static inline 
int kos_create_kern_thread(void *entry)
{
    int pid;
    __asm__ __volatile__ (
        "call *__imp__CreateThread"
        :"=a"(pid)
        :"b"(1),"c"(entry),"d"(0)
        :"memory"
    );
     __asm__ __volatile__ ("":::"ebx","ecx","edx","esi","edi");
     return pid;
}

static inline 
evhandle_t kos_create_event(kevent_t *ev, u32 flags)
{
    evhandle_t evh;
    __asm__ __volatile__ (
        "call *__imp__CreateEvent"
        :"=A"(evh.raw)
        :"S" (ev), "c"(flags)
        :"memory"
    );
    __asm__ __volatile__ ("":::"ebx","ecx","edx","esi", "edi");
    return evh;
}
 
static inline 
void kos_raise_event(evhandle_t evh, u32 flags, kevent_t *ev)
{
    __asm__ __volatile__ (
        "call *__imp__RaiseEvent"
        ::"a"(evh.handle),"b"(evh.euid),"d"(flags),"S" (ev)
        :"memory"
    );
    __asm__ __volatile__ ("":::"ebx","ecx","edx","esi","edi");
}
 
static inline 
void kos_wait_event(evhandle_t evh)
{
    __asm__ __volatile__ (
        "call *__imp__WaitEvent"
        ::"a"(evh.handle),"b"(evh.euid)
    );
    __asm__ __volatile__ ("":::"ebx","ecx","edx","esi","edi");
}
 
static inline 
int kos_wait_event_timeout(evhandle_t evh, int timeout)
{
    int retval;
    __asm__ __volatile__ (
    "call *__imp__WaitEventTimeout"
    :"=a"(retval)
    :"a"(evh.handle),"b"(evh.euid), "c"(timeout));
    __asm__ __volatile__ ("":::"ebx","ecx","edx","esi","edi");
    return retval;
}
 
static inline 
void kos_destroy_event(evhandle_t evh)
{
    __asm__ __volatile__ (
        "call *__imp__DestroyEvent"
        ::"a"(evh.handle),"b"(evh.euid)
    );
    __asm__ __volatile__ ("":::"ebx","ecx","edx","esi","edi");
}
 
static inline 
u32 kos_get_event(kevent_t *ev)
{
    u32  handle;
    __asm__ __volatile__ (
        "call *__imp__GetEvent"
        :"=a"(handle)
        :"D"(ev)
        :"memory"
    );
    __asm__ __volatile__ ("":::"ebx","ecx","edx", "esi","edi");
    return handle;
}

static inline 
u32 kos_get_page_addr(void *mem)
{
    u32 retval;
    __asm__ __volatile__ (
        "call *__imp__GetPgAddr \n\t"
        :"=a" (retval)
        :"a" (mem) 
    );
    return retval;
};

static inline 
void kos_commit_pages(void *mem, u32 page, u32 size)
{
    size = (size+4095) & ~4095;
    __asm__ __volatile__ (
        "call *__imp__CommitPages"
        ::"a" (page), "b"(mem),"c"(size>>12)
        :"edx" 
    );
     __asm__ __volatile__ ("":::"eax","ebx","ecx");
};

static inline 
void kos_unmap_pages(void *mem, size_t size)
{
     size = (size+4095) & ~4095;
     __asm__ __volatile__ (
       "call *__imp__UnmapPages"
        ::"a" (mem), "c"(size>>12)
        :"edx"
    );
    __asm__ __volatile__ ("":::"eax","ecx");
};

static inline 
void kos_usleep(u32 delay)
{
     if( !delay )
        delay++;
     delay*= 500;

     while(delay--)
        __asm__ __volatile__(
            "xorl %%eax, %%eax \n\t"
            "cpuid \n\t"
            :::"eax","ebx","ecx","edx"
        );
     };

static inline 
void kos_udelay(u32 delay)
{
    if(!delay) delay++;
    delay*= 100;

    while(delay--)
    {
        __asm__ __volatile__(
            "xorl %%eax, %%eax \n\t"
            "cpuid"
            :::"eax","ebx","ecx","edx"
        );
    }
}

static inline 
void kos_mdelay(u32 time)
{
    time /= 10;
    if(!time) time = 1;
    __asm__ __volatile__ (
        "call *__imp__Delay"
        ::"b" (time)
    );
    __asm__ __volatile__ ("":::"ebx");
};

static inline 
u32 kos_pci_api(int cmd)
{
    u32 retval;
    __asm__ __volatile__(
        "call *__imp__PciApi \n\t"
        "movzxb %%al, %%eax"
        :"=a" (retval)
        :"a" (cmd)
        :"cc"
    );
    return retval;
};

static inline 
u32 kos_get_service(const char *name)
{
    u32 handle;
    __asm__ __volatile__(
        "pushl %%eax \n\t"
        "call *__imp__CreateObject \n\t"
        :"=a" (handle)
        :"a" (name)
        :"ebx","ecx","edx","esi", "edi"
    );
    return handle;
};

static inline 
u32 safe_cli(void)
{
    u32 ifl;
    __asm__ __volatile__(
        "pushf\n\t"
        "popl %0\n\t"
        "cli\n"
        :"=r" (ifl)
    );
    return ifl;
}

static inline 
void safe_sti(u32 efl)
{
     if (efl & (1<<9))
        __asm__ __volatile__("sti");
}

static inline 
u32 get_eflags(void)
{
    u32 val;
    __asm__ __volatile__(
        "pushfl\n\t"
        "popl %0\n"
        : "=r" (val)
    );
    return val;
}

static inline 
void __clear (void * dst, unsigned len)
{
    u32 tmp;
    __asm__ __volatile__(
        "cld \n\t"
         "rep stosb \n"
        :"=c"(tmp),"=D"(tmp)
        :"a"(0),"c"(len),"D"(dst)
    );
    __asm__ __volatile__("":::"ecx","edi");
};

static inline 
void out8(const u16 port, const u8 val)
{
    __asm__ __volatile__("outb  %1, %0\n" : : "dN"(port), "a"(val));
}

static inline 
void out16(const u16 port, const u16 val)
{
    __asm__ __volatile__("outw  %1, %0\n" : : "dN"(port), "a"(val));
}

static inline 
void out32(const u16 port, const u32 val)
{
    __asm__ __volatile__("outl  %1, %0\n" : : "dN"(port), "a"(val));
}

static inline 
u8 in8(const u16 port)
{
    u8 tmp;
    __asm__ __volatile__("inb %1, %0\n" : "=a"(tmp) : "dN"(port));
    return tmp;
};

static inline 
u16 in16(const u16 port)
{
    u16 tmp;
    __asm__ __volatile__("inw %1, %0\n" : "=a"(tmp) : "dN"(port));
    return tmp;
};

static inline 
u32 in32(const u16 port)
{
    u32 tmp;
    __asm__ __volatile__("inl %1, %0\n" : "=a"(tmp) : "dN"(port));
    return tmp;
};

static inline 
void kos_delay(int time)
{
    __asm__ __volatile__(
        "call *__imp__Delay"
        ::"b" (time)
    );
    __asm__ __volatile__("":::"ebx");
}

static inline 
void kos_change_task(void)
{
    __asm__ __volatile__(
        "call *__imp__ChangeTask"
    );
}

static inline 
void kos_sys_set_screen(int width, int height, int pitch)
{
    __asm__ __volatile__(
        "call *__imp__SetScreen"
        ::"a" (width-1),"d"(height-1), "c"(pitch)
    );
    __asm__ __volatile__("" :::"eax","ecx","edx");
}

static inline
void kos_dbg_string(char *text)
{
    __asm__ __volatile__(
        "call *__imp__SysMsgBoardStr"
        ::"S" (text)
    );
};

static inline 
void *vzalloc(unsigned long size)
{
    void *mem = kos_kern_alloc(size);
    if(mem)
        memset(mem, 0, size);
    return mem;
};

static inline 
int kos_fs_service(kos_fs_t *k, int* err){
    int status;
    __asm__ __volatile__(
        "call *__imp__FS_Service"
        :"=a" (status), "=b" (*err) 
        :"b" (k)
        :"memory"
    );
    __asm__ __volatile__ ("":::"ebx","ecx","edx","esi","edi");
    return status;
}


#endif // _KOS_KERNEL_H_