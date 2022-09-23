#include <stdio.h>
#include "State.h"
#include "StopState.h"

void doActionStop(struct state *state)
{
    printf("Do action stop !\n");
}

struct state_operations stopState_ops = {
    .doAction = doActionStop,
};

void init_stopState(struct stopState *stopState)
{
    init_state(&stopState->state);
    stopState->state.ops = &stopState_ops;
}