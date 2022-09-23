#include "Memento.h"
#include <stdio.h>

char *getState_f(struct memento *memento)
{
    return memento->state;
}

struct memento_operations memento_ops = {
    .getState = getState_f,
};

void init_memento(struct memento *memento)
{
    memento->ops = &memento_ops;
}