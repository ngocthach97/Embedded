#include "Square.h"
#include <stdio.h>

void draw_square(struct shape *shape)
{
    printf("Draw square ! \n");
}

struct shape_operations square_pos = {
    .draw = draw_square,
};

void init_square(struct square *square)
{
    init_shape(&square->shape);
    square->shape.name = "square";
    square->shape.ops = &square_pos;
}