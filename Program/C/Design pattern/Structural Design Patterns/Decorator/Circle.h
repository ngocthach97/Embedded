#ifndef CIRCLE_DECORATOR
#define CIRCLE_DECORATOR
#include "Shape.h"

struct circle
{
    struct shape shape;
};

void init_circle(struct circle *);

#endif