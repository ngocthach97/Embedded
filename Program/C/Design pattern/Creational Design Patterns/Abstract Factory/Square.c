#include "Square.h"
#include <stdio.h>
#include <stdlib.h>

void draw_square(struct shape *shape)
{
    printf("Draw square ! \n");
}

void free_square(struct shape *shape)
{
    printf("Free square ! \n");
}

struct shape_operations square_ops = {
    .draw = draw_square,
    .free = free_square,
};

void init_square(struct square *square)
{
    init_shape(&square->shape);
    square->shape.ops = &square_ops;
}
