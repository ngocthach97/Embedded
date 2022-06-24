#include "Shape.h"
#include <stdlib.h>

void init_shape(struct shape *shape)
{
    shape->name = NULL;
    shape->ops = NULL;
}