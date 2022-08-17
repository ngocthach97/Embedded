#include "Shape.h"
#include <stdlib.h>

void shape_init(struct shape *shape, struct color *color)
{
    shape->name = NULL;
    shape->ops = NULL;
    shape->color = color;
}