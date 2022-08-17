#ifndef HEXA_
#define HEXA_
#include "Observer.h"

struct hexa
{
    struct observer observer;
};

void init_hexa(struct hexa *);

#endif