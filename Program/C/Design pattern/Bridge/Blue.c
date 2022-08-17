#include "Blue.h"
#include <stdio.h>

void render_blue_color(struct color *color)
{
    printf("Render blue color !\n");
}
struct color_operations blue_color_pos = {
    .render = render_blue_color,
};

void init_blue_color(struct blue *blue)
{
    init_color(&blue->color);
    blue->color.ops = &blue_color_pos;
    blue->color.name = "blue";
}