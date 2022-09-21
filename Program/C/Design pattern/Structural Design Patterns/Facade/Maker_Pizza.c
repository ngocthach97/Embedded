#include "Maker_Pizza.h"
#include <stdlib.h>
#include "Veggie_Pizza.h"
#include "Clam_Pizza.h"
#include "Cheese_Pizza.h"
#include "Pizza.h"

void init_maker_pizza(struct maker_pizza *maker)
{
    struct cheese_pizza *cheese = (struct cheese_pizza *)malloc(sizeof(struct cheese_pizza));
    maker->cheese = cheese;
    init_cheese_pizza(maker->cheese);

    struct clam_pizza *clam = (struct clam_pizza *)malloc(sizeof(struct clam_pizza));
    maker->clam = clam;
    init_clam_pizza(maker->clam);

    struct veggie_pizza *veggie = (struct veggie_pizza *)malloc(sizeof(struct veggie_pizza));
    maker->veggie = veggie;
    init_veggie_pizza(maker->veggie);
}

void cut_cheese_pizza_maker(struct maker_pizza *maker_pizza)
{
    cut_pizza(&maker_pizza->cheese->pizza);
}