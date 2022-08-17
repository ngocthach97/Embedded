#include "Color.h"
#include <stdlib.h>

void init_color(struct color *color)
{
    color->name = NULL;
    color->ops = NULL;
}