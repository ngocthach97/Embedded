#include <stdio.h>
#include <stdlib.h>
#include "RoundedRectangle.h"

void draw_roundedRectangle(struct shape *shape)
{
    printf("Draw rounded rectangle \n");
}

void free_roundedRectangle(struct shape *shape)
{
    printf("Free rounded rectangle \n");
}

struct shape_operations roundedRectangle_ops = {
    .draw = draw_roundedRectangle,
    .free = free_roundedRectangle,
};

void init_roundedRectangle(struct roundedRectangle *roundedRectangle)
{
    init_shape(&roundedRectangle->shape);
    roundedRectangle->shape.ops = &roundedRectangle_ops;
}
