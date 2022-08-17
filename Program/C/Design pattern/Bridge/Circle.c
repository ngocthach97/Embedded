#include "Circle.h"
#include <stdio.h>

void draw_cricle(struct shape *shape, struct color *color)
{
    printf("Draw %s color %s!\n",shape->name,color->name);
}

struct shape_operations cricle_shape_ops = {
    .draw = draw_cricle,
};

void init_circle(struct circle *circle, struct color *color)
{
    shape_init(&circle->shape, color);
    circle->shape.ops = &cricle_shape_ops;
    circle->shape.name = "circle";
}