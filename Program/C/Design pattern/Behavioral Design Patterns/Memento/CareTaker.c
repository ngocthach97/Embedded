#include "CareTaker.h"
#include <stdio.h>

void add_f(struct caretaker *caretaker, struct memento* memento)
{
    for (int i = 0; i < size; i++)
    {
        if (caretaker->list[i] == NULL)
        {
            caretaker->list[i] = memento;
            break;
        }
    }
}

struct memento *get_f(struct caretaker *caretaker, int index)
{
    return caretaker->list[index];
}

struct caretaker_operations caretaker_ops = {
    .add = add_f,
    .get = get_f,
};

void init_caretaker(struct caretaker *caretaker)
{
    caretaker->ops = &caretaker_ops;
}