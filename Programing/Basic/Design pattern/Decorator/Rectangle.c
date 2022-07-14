#include "Rectangle.h"
#include "Shape.h"
#include <stdlib.h>
#include <stdio.h>
void draw_rectangle(struct shape *shape)
{
    printf("draw rectangle !\n");
}

struct shape_operations rectangle_ops = {
    .draw = draw_rectangle,
};

void init_rectangle(struct rectangle *rectangle)
{
    init_shape(&rectangle->shape);
    rectangle->shape.ops = &rectangle_ops;
}