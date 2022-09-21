#ifndef PACKING_BUILD_
#define PACKING_BUILD_

struct packing
{
    struct packing_ops *ops;
};

struct packing_ops
{
    char *(*pack)(struct packing *);
};

void init_packing(struct packing *);
#endif