#ifndef COMPONENT_
#define COMPONENT_

#define SIZE 32

struct component
{
    char *name;
    struct component_pos *pos;
    struct component *children[SIZE];
    int index;
};

struct component_pos
{
    void (*_add)(struct component *);
    void (*_render)(struct component *);
};

void init_component(struct component *);

void add_component(struct component *, struct component *);

void get_component(struct component *);

#endif