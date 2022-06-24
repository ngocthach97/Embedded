#include <stdio.h>
#include <stdlib.h>
#include "Color.h"
#include "Blue.h"
#include "Red.h"
#include "Circle.h"

int main(int argv, const char *argc[])
{
    // cricle 1
    struct red *red = (struct red *)malloc(sizeof(struct red));
    init_red_color(red);

    struct circle *circle1 = (struct circle *)malloc(sizeof(struct circle));
    init_circle(circle1, &red->color);

    draw_shape(&circle1->shape,circle1->shape.color);

     // cricle 2
    struct blue *blue = (struct blue *)malloc(sizeof(struct blue));
    init_blue_color(blue);

    struct circle *circle2 = (struct circle *)malloc(sizeof(struct circle));
    init_circle(circle2, &blue->color);

    draw_shape(&circle2->shape,circle2->shape.color);

    return 0;
}