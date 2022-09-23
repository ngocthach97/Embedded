#include <stdio.h>
#include <stdlib.h>
#include "Context.h"
#include "State.h"
#include "StopState.h"
#include "StartState.h"

int main(int agrv, const char *argc[])
{
    struct stopState *stopState = (struct stopState *)malloc(sizeof(struct stopState));
    init_stopState(stopState);

    struct startState *startState = (struct startState *)malloc(sizeof(struct startState));
    init_startState(startState);

    struct context *context = (struct context *)malloc(sizeof(struct context));
    init_context(context, &stopState->state);

    _doAction(&stopState->state);

    _doAction(&startState->state);
    
    _doAction(&stopState->state);
    
    _doAction(&stopState->state);

    return 0;
}
