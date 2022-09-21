#ifndef SHAPE_PROTOTYPE
#define SHAPE_PROTOTYPE

struct shape
{
    int ID;
    char *type;
    struct shape_pos *shape_pos;
};

struct shape_pos
{
    struct shape *(*clone_shape)(struct shape *);
    int (*get_ID)(struct shape *);
    void (*set_ID)(struct shape *, int ID);
    char *(*get_type)(struct shape *);
    void (*set_type)(struct shape *, char *type);
};

void init_shape(struct shape *);

static inline struct shape *clone_shape(struct shape *shape)
{
    return shape->shape_pos->clone_shape(shape);
}

static inline int get_ID(struct shape *shape)
{
    return shape->shape_pos->get_ID(shape);
}

static inline void set_ID(struct shape *shape, int ID)
{
    shape->shape_pos->set_ID(shape, ID);
}

static inline char *get_type(struct shape *shape)
{
    return shape->shape_pos->get_type(shape);
}

static inline void set_type(struct shape *shape, char *type)
{
    shape->shape_pos->set_type(shape, type);
}

#endif