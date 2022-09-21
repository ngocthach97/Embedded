#ifndef BOTTLE_BUILD_
#define BOTTLE_BUILD_
#include "Packing.h"

struct bottle
{
    struct packing packing;
};

void init_bottle(struct bottle *);

#endif