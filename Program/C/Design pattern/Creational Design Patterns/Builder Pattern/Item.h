#ifndef ITEM_BUILD_
#define ITEM_BUILD_
#include "Packing.h"

struct item
{
    struct item_ops *ops;
};

struct item_ops
{
    char *(*name)(struct item *);
    struct packing *(*packing)(struct item *);
    float *(*price)(struct item *);
};

void init_item(struct item *);

#endif
