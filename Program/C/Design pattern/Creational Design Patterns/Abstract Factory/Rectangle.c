#include <stdio.h>
#include <stdlib.h>
#include "Rectangle.h"

void draw_rectangle(struct shape *shape)
{
    printf("Draw rectangle !\n");
}
void free_rectangle(struct shape *shape)
{
    printf("Free rectangle !\n");
}

struct shape_operations rectangle_ops = {
    .draw = draw_rectangle,
    .free = free_rectangle,
};

void init_rectangle(struct rectangle *rectangle)
{
    init_shape(&rectangle->shape);
    rectangle->shape.ops = &rectangle_ops;
}
