#include <kos_io.h>

int kos_get_fileinfo(const char *path, kos_bdfe_t *info)
{
   int err;
   kos_fs_t k;
   k.p00   = 5;
   k.p04dw = 0;
   k.p08dw = 0;
   k.p12   = 0;
   k.bdfe  = info;
   k.p20   = 0;
   k.p21   = path;
   return kos_fs_service(&k, &err);
}
