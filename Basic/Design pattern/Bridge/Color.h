#ifndef COLOR_
#define COLOR_

struct color
{
    char *name;
    struct color_operations *ops;
};

struct color_operations
{
    void (*render)(struct color *);
};

void init_color(struct color *);

static inline void render_color(struct color *color)
{
    color->ops->render(color);
}

#endif