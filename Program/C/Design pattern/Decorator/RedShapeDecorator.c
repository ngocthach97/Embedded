#include "RedShapeDecorator.h"
#include "ShapeDecorator.h"
#include <stdio.h>
#include "ShapeDecorator.h"
void draw_red_shape_decorator(struct shape *shape)
{
    printf("draw red shape decorator ! \n");
}
struct shape_operations red_shape_decorator_ops = {
    .draw = draw_red_shape_decorator,
};

void init_red_shape_decorator(struct red_shape_decorator *red_shape_decorator, struct shape *shape)
{
    init_shape_decorator(&red_shape_decorator->shape_decorator, shape);
    red_shape_decorator->shape_decorator.shape.ops = &red_shape_decorator_ops;
}