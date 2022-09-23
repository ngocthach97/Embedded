#include <stdio.h>
#include "StartState.h"
#include "State.h"
void doActionStart(struct state *state)
{
    printf("Do action start !\n");
}

struct state_operations startState_ops = {
    .doAction = doActionStart,
};

void init_startState(struct startState *startState)
{
    init_state(&startState->state);
    startState->state.ops = &startState_ops;
}