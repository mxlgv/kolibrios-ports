#include <linux/types.h>
#include <linux/gfp.h>
#include <linux/spinlock.h>
#include <linux/dma-mapping.h>
#include <linux/scatterlist.h>
#include <kos_kernel.h>

void *dma_alloc_coherent(struct device *dev, size_t size,
                         dma_addr_t *dma_handle, gfp_t gfp)
{
    void *ret;

    size = ALIGN(size,32768);
    ret = (void *)kos_kern_alloc(size);

    if (ret) {
        __builtin_memset(ret, 0, size);
        *dma_handle = kos_get_page_addr(ret);
    }

    return ret;
}