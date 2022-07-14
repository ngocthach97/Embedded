#include <stdio.h>
#include <stdlib.h>
#include "Circle.h"
#include "RedShapeDecorator.h"
#include "Rectangle.h"

int main(int argc, const char *argv[])
{
    struct circle *circle = (struct circle *)malloc(sizeof(struct circle));

    struct rectangle *rectangle = (struct rectangle *)malloc(sizeof(struct rectangle));

    struct red_shape_decorator *red_shape_decorator_1 = (struct red_shape_decorator *)malloc(sizeof(struct red_shape_decorator));

    struct red_shape_decorator *red_shape_decorator_2 = (struct red_shape_decorator *)malloc(sizeof(struct red_shape_decorator));

    init_red_shape_decorator(red_shape_decorator_1, &circle->shape);

    init_red_shape_decorator(red_shape_decorator_2, &rectangle->shape);


    draw_shape(&red_shape_decorator_1->shape_decorator.shape);


    draw_shape(&red_shape_decorator_2->shape_decorator.shape);

    return 0;
}