#include "Red.h"
#include <stdio.h>

void render_red_color(struct color *color)
{
    printf("Render red color !\n");
}
struct color_operations red_color_pos = {
    .render = render_red_color,
};

void init_red_color(struct red *red)
{
    init_color(&red->color);
    red->color.ops = &red_color_pos;
    red->color.name = "red";
}