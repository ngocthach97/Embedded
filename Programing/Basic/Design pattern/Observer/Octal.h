#ifndef OCTAL_
#define OCTAL_
#include "Observer.h"

struct octal
{
    struct observer observer;
};

void init_octal(struct octal *);

#endif