#ifndef PIZZA_M_
#define PIZZA_M_
#include "Cheese_Pizza.h"
#include "Clam_Pizza.h"
#include "Veggie_Pizza.h"

struct maker_pizza
{
    struct cheese_pizza *cheese;
    struct clam_pizza *clam;
    struct veggie_pizza *veggie;
};

void init_maker_pizza(struct maker_pizza *);

void cut_cheese_pizza_maker(struct maker_pizza *);

#endif