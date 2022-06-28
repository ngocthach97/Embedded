#include "Rectangle.h"
#include "Shape.h"

struct shape_pos rectangle_pos = {

};

void init_rectangle(struct rectangle *rectangle)
{
    init_shape(&rectangle->shape);
    rectangle->shape.shape_pos = &rectangle_pos;
}