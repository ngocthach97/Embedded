#ifndef SHAPE_DECORATOR_DEMO
#define SHAPE_DECORATOR_DEMO
#include "Shape.h"

struct shape_decorator
{
    struct shape *_inner;
    struct shape shape;
};

void init_shape_decorator(struct shape_decorator *, struct shape *);

#endif