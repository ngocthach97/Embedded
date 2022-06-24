#ifndef SHAPE_
#define SHAPE_
#include "Color.h"

struct shape
{
    char *name;
    struct color *color;
    struct shape_operations *ops;
};

struct shape_operations
{
    void (*draw)(struct shape *, struct color *);
};

void shape_init(struct shape *, struct color *);

static inline void draw_shape(struct shape *shape, struct color *color)
{
    shape->ops->draw(shape,color);
}

#endif