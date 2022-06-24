#include "Square.h"
#include "Circle.h"
#include "Rectangle.h"
#include "ShapeFactory.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct shape *shape_factory(const char *name)
{
    struct shape *shape = 0;
    struct square *square;
    struct circle *circle;
    struct rectangle *rectangle;
    if (!strcmp(name, "square"))
    {
        square = malloc(sizeof(*square));
        if (!square)
            return 0;

        init_square(square);
        shape = &square->shape;
    }
    else if (!strcmp(name, "circle"))
    {
        circle = malloc(sizeof(*circle));
        if (!circle)
            return 0;

        init_circle(circle);
        shape = &circle->shape;
    }

    else if (!strcmp(name, "rectangle"))
    {
        rectangle = malloc(sizeof(*rectangle));
        if (!rectangle)
            return 0;

        init_rectangle(rectangle);
        shape = &rectangle->shape;
    }
    return shape;
}