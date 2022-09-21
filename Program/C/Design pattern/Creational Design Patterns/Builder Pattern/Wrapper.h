#ifndef WRAPPER_BUILD_
#define WRAPPER_BUILD_
#include "Packing.h"
struct wrapper
{
    struct packing packing;
};

void init_wapper(struct wrapper *);

#endif