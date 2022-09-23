#include "Context.h"
#include "State.h"

void setState_f(struct context *context, struct state *state)
{
    context->state = state;
}

struct state *getState_f(struct context *context)
{
    return context->state;
}

struct context_operations context_ops = {
    .getState = getState_f,
    .setState = setState_f,
};

void init_context(struct context *context, struct state *state)
{
    context->state = state;
    context->ops = &context_ops;
}