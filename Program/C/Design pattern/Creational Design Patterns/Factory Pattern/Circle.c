#include "Circle.h"
#include <stdio.h>

void draw_circle(struct shape *shape)
{
    printf("Draw circle ! \n");
}

struct shape_operations circle_pos = {
    .draw = draw_circle,
};

void init_circle(struct circle *circle)
{
    init_shape(&circle->shape);
    circle->shape.name = "circle";
    circle->shape.ops = &circle_pos;
}
