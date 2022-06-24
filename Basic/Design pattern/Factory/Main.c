#include <stdio.h>
#include <stdlib.h>
#include "ShapeFactory.h"

int main(int argc, const char *argv[])
{
    struct shape *shape = shape_factory("square");
    draw_shape(shape);
    return 0;
}