#include "Circle.h"
#include "Shape.h"

struct shape *clone_circle(struct shape *shape)
{
    return shape;
}

struct shape_pos circle_pos = {
    .clone_shape = clone_circle,
};

void init_circle(struct circle *circle)
{
    init_shape(&circle->shape);
    circle->shape.shape_pos = &circle_pos;
}