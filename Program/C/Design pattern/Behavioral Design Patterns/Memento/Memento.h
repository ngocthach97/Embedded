#ifndef MEMENTO_
#define MEMENTO_

struct memento
{
    char *state;
    struct memento_operations *ops;
};

struct memento_operations
{
    char *(*getState)(struct memento *);
};

void init_memento(struct memento *);

static inline char *_getState_memento(struct memento *memento)
{
    return memento->ops->getState(memento);
}

#endif