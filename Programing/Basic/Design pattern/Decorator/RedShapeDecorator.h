#ifndef RED_SHAPE_DECORATOR
#define RED_SHAPE_DECORATOR
#include "Shape.h"
#include "ShapeDecorator.h"

struct red_shape_decorator
{
    struct shape_decorator shape_decorator;
};

void init_red_shape_decorator(struct red_shape_decorator *, struct shape *);

#endif