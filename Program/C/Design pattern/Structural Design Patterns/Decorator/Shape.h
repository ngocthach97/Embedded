#ifndef SHAPE_DECORATOR
#define SHAPE_DECORATOR

struct shape
{
    struct shape_operations *ops;
};

struct shape_operations
{
    void (*draw)(struct shape *);
};

void init_shape(struct shape *);

static inline void draw_shape(struct shape *shape)
{
    shape->ops->draw(shape);
}

#endif