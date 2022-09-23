#ifndef STOP_STATE_
#define STOP_STATE_
#include "State.h"

struct stopState
{
    struct state state;
};

void init_stopState(struct stopState *);

#endif