#include "Originator.h"
#include <stdlib.h>

char *_getState_f(struct originator *originator)
{
    return originator->state;
}

void _setState_f(struct originator *originator, char *state)
{
    originator->state = state;
}

struct memento *_saveStateToMemento_f(struct originator *originator)
{
    struct memento *memento = (struct memento *)malloc(sizeof(struct memento));
    init_memento(memento);
    memento->state = originator->state;
    return memento;
}

void _getStateFromMemento_f(struct memento *memento, struct originator *originator)
{
    originator->state = _getState_memento(memento);
}

struct originator_operations originator_ops = {
    .getState = _getState_f,
    .setState = _setState_f,
    .getStateFromMemento = _getStateFromMemento_f,
    .saveStateToMemento = _saveStateToMemento_f,
};

void init_originator(struct originator *originator)
{
    originator->ops = &originator_ops;
}