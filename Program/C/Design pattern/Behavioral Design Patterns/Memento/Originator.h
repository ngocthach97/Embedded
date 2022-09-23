#ifndef ORIGINATOR_
#define ORIGINATOR_
#include "Memento.h"

struct originator
{
    char *state;
    struct originator_operations *ops;
};

struct originator_operations
{
    char *(*getState)(struct originator *);
    void (*setState)(struct originator *, char *);
    struct memento *(*saveStateToMemento)(struct originator *);
    void (*getStateFromMemento)(struct memento *, struct originator *);
};

void init_originator(struct originator *);

static inline void _setState_originator(struct originator *originator, char *state)
{
    originator->ops->setState(originator, state);
}

static inline char *_getState_originator(struct originator *originator)
{
    return originator->ops->getState(originator);
}

static inline struct memento *_saveStateToMemento_originator(struct originator *originator)
{
    return originator->ops->saveStateToMemento(originator);
}

static inline void _getStateFromMemento_originator(struct memento *memento, struct originator *originator)
{
    return originator->ops->getStateFromMemento(memento, originator);
}

#endif