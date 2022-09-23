#ifndef CONTEXT_
#define CONTEXT_
#include "State.h"

struct context
{
    struct state *state;
    struct context_operations *ops;
};

struct context_operations
{
    void (*setState)(struct context *, struct state *);
    struct state *(*getState)(struct context *);
};

void init_context(struct context *, struct state *);

#endif