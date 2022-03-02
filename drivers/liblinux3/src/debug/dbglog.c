#include <kos_kernel.h>
#include <kos_io.h>
#include <linux/mutex.h>

#pragma pack(pop)

typedef struct {
  char *path;
  int  offset;
} dbgfile_t;

static dbgfile_t dbgfile;

#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define __va_copy(d,s)	__builtin_va_copy(d,s)

typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list    va_list;

#define arg(x) va_arg (ap, u32_t)

int dbg_open(char *path) {
    kos_bdfe_t info;
    dbgfile.offset = 0;
    if(kos_get_fileinfo(path, &info)) {
        if(!kos_create_file(path)) {
            dbgfile.path = path;
            return true;
        }
        else return false;
    }
    kos_set_file_size(path, 0);
    dbgfile.path   = path;
    dbgfile.offset = 0;
    return true;
}

extern int vsnprintf(char *s, size_t n, const char *format, va_list arg);

int printf(const char* format, ...)
{
    char  txtbuf[1024];
    int   len = 0;
    va_list ap;
    va_start(ap, format);
    if (format)
        len = vsnprintf(txtbuf, 1024, format, ap);
    va_end(ap);
    if( len )
        kos_dbg_string(txtbuf);
    return len;
}

int dbgprintf(const char* format, ...)
{
    char      txtbuf[1024];
    unsigned  writes;
    int       len = 0;

    va_list   ap;

    va_start(ap, format);
    if (format)
      len = vsnprintf(txtbuf, 1024, format, ap);
    va_end(ap);

    if( len )
    {
        if( dbgfile.path)
        {
/*  do not write into log file if interrupts disabled */

            if ( get_eflags() & (1 << 9) )
            {
                kos_write_file(dbgfile.path,txtbuf,dbgfile.offset,len,&writes);
                dbgfile.offset+=writes;
            };
        }
        else kos_dbg_string(txtbuf);
    };
    return len;
}