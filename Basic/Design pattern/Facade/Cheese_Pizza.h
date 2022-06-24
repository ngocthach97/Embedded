#ifndef PIZZA_CH_
#define PIZZA_CH_
#include "Pizza.h"

struct cheese_pizza
{
    struct pizza pizza;
};

void init_cheese_pizza(struct cheese_pizza *);

#endif