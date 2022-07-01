#include "Rectangle.h"
#include <stdio.h>

void draw_rectangle(struct shape *shape)
{
    printf("Draw rectangle ! \n");
}

struct shape_operations rectangle_pos = {
    .draw = draw_rectangle,
};

void init_rectangle(struct rectangle *rectangle)
{
    init_shape(&rectangle->shape);
    rectangle->shape.name = "rectangle";
    rectangle->shape.ops = &rectangle_pos;
}
