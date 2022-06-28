#include "ShapeCache.h"
#include <stdlib.h>
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

void init_shape_cache(struct shape_cache *shape_cache)
{
    shape_cache->index = 0;
}

struct shape *get_shape(struct shape_cache *shape_cache, int ID)
{
    for (int i = 0; i < shape_cache->index; i++)
    {
        if (get_ID(shape_cache->list_shape[i]) == ID)
        {
            return clone_shape(shape_cache->list_shape[i]);
        }
    }
    return NULL;
}

void load_cache(struct shape_cache *shape_cache)
{
    struct circle *circle = (struct circle *)malloc(sizeof(struct circle));
    init_circle(circle);
    set_ID(&circle->shape, 1);
    set_type(&circle->shape, "circle");
    shape_cache->list_shape[shape_cache->index++] = &circle->shape;

    struct rectangle *rectangle = (struct rectangle *)malloc(sizeof(struct rectangle));
    init_rectangle(rectangle);
    set_ID(&rectangle->shape, 2);
    set_type(&rectangle->shape, "rectangle");
    shape_cache->list_shape[shape_cache->index++] = &rectangle->shape;

    struct square *square = (struct square *)malloc(sizeof(struct square));
    init_square(square);
    set_ID(&square->shape, 3);
    set_type(&square->shape, "square");
    shape_cache->list_shape[shape_cache->index++] = &square->shape;
}
