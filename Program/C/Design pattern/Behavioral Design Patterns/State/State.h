#ifndef STATE_
#define STATE_

struct state
{
    struct state_operations *ops;
};

struct state_operations
{
    void (*doAction)(struct state *);
};

void init_state(struct state *);

static inline void _doAction(struct state *state)
{
    state->ops->doAction(state);
}

#endif