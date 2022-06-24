
#ifndef CHEESE_PIZZA_H_
#define CHEESE_PIZZA_H_

#include "Pizza.h"

struct cheese_pizza {
	struct pizza pizza;
};

void init_cheese_pizza(struct cheese_pizza *);

#endif