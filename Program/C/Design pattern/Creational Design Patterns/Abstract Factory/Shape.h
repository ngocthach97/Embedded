#ifndef SHAPE_AF_
#define SHAPE_AF_

struct shape
{
    struct shape_operations *ops;
};

struct shape_operations
{
    void (*draw)(struct shape *);
    void (*free)(struct shape *);
};

void init_shape(struct shape *);

static inline void draw_shape(struct shape *shape)
{
    shape->ops->draw(shape);
}

static inline void free_shape(struct shape *shape)
{
    shape->ops->free(shape);
}

#endif