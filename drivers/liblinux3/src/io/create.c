#include <kos_io.h>

int kos_create_file(const char *path)
{
    int err;
    kos_fs_t  k;
    k.p00   = 2;
    k.p04dw = 0;
    k.p08dw = 0;
    k.p12   = 0;
    k.p20   = 0;
    k.p21   = path;
    return kos_fs_service(&k, &err);
};
