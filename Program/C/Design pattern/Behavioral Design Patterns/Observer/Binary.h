#ifndef BINARY_
#define BINARY_
#include "Observer.h"

struct binary
{
    struct observer observer;
};

void init_binary(struct binary *);

#endif