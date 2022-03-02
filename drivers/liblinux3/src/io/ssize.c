#include <kos_io.h>

int kos_set_file_size(const char *path, unsigned size)
{
     kos_fs_t  k;
     int err;
     k.p00   = 4;
     k.p04dw = size;
     k.p08dw = 0;
     k.p20   = 0;
     k.p21   = path;
     return kos_fs_service(&k, &err);
}