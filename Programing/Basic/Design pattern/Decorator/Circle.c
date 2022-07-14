#include "Circle.h"
#include "Shape.h"
#include <stdlib.h>
#include <stdio.h>

void draw_circle(struct shape *shape)
{
    printf("draw circle !\n");
}

struct shape_operations circle_ops = {
    .draw = draw_circle,
};

void init_circle(struct circle *circle)
{
    init_shape(&circle->shape);
    circle->shape.ops = &circle_ops;
}