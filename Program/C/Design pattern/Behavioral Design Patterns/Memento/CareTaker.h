#ifndef CARETAKER_
#define CARETAKER_
#include "Memento.h"

#define size 10

struct caretaker
{
    struct memento *list[size];
    struct caretaker_operations *ops;
};

struct caretaker_operations
{
    void (*add)(struct caretaker *, struct memento *);
    struct memento *(*get)(struct caretaker *, int index);
};

void init_caretaker(struct caretaker *);

static inline void _add(struct caretaker *caretaker, struct memento *memento)
{
    caretaker->ops->add(caretaker, memento);
}

static inline struct memento *_get(struct caretaker *caretaker, int index)
{
    return caretaker->ops->get(caretaker, index);
}

#endif