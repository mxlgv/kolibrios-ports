#ifndef _KOS_IO_H_
#define _KOS_IO_H_

#include <kos_kernel.h>

#pragma pack(push, 1)

typedef struct {
    u8 sec;
    u8 min;
    u8 hour;
    u8 rsv;
} kos_detime_t;

typedef struct {
    u8  day;
    u8  month;
    u16 year;
} kos_dedate_t;

typedef struct {
    u32 attr;
    u32 flags;
    union {
        kos_detime_t  ctime;
        u32 cr_time;
    };
    union {
        kos_dedate_t  cdate;
        u32 cr_date;
    };
    union {
        kos_detime_t  atime;
        u32 acc_time;
    };
    union {
        kos_dedate_t  adate;
        u32 acc_date;
    };
    union {
        kos_detime_t  mtime;
        u32 mod_time;
    };
    union {
        kos_dedate_t  mdate;
        u32  mod_date;
    };
    u32 size;
    u32 size_high;
} kos_bdfe_t;

#pragma pack(pop)

int kos_get_fileinfo(const char *path, kos_bdfe_t *info);
int kos_create_file(const char *path);
int kos_set_file_size(const char *path, unsigned size);
int kos_write_file(const char *path, const void *buff, unsigned offset, unsigned count, unsigned *writes);

#endif // _KOS_IO_H_