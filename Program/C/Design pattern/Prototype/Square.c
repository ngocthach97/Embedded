#include "Square.h"
#include "Shape.h"

struct shape_pos square_pos = {

};

void init_square(struct square *square)
{
    init_shape(&square->shape);
    square->shape.shape_pos = &square_pos;
}