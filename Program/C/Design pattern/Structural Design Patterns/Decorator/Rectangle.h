#ifndef RECTANGLE_DECORATOR
#define RECTANGLE_DECORATOR
#include "Shape.h"

struct rectangle
{
    struct shape shape;
};

void init_rectangle(struct rectangle *);

#endif