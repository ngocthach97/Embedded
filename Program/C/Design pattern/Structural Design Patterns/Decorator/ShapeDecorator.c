#include "ShapeDecorator.h"
#include "Shape.h"
#include <stdio.h>

void draw_shape_decorator(struct shape *shape)
{
    printf("draw shap decorator ! \n");
}

struct shape_operations shape_decorator_ops = {
    .draw = draw_shape_decorator,
};
void init_shape_decorator(struct shape_decorator *shape_decorator, struct shape *shape)
{
    init_shape(&shape_decorator->shape);
    shape_decorator->shape.ops = &shape_decorator_ops;
    shape_decorator->_inner = shape;
}