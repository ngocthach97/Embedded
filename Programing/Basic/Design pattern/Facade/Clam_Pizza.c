#include "Clam_Pizza.h"
#include "Pizza.h"
#include <stdio.h>

void bake_clam_pizza(struct pizza *pizza)
{
    printf("Bake clam pizza ! \n");
}

void box_clam_pizza(struct pizza *pizza)
{
    printf("Box clam pizza ! \n");
}

void cut_clam_pizza(struct pizza *pizza)
{
    printf("Cut clam pizza ! \n");
}

void prepare_clam_pizza(struct pizza *pizza)
{
    printf("Prepare clam pizza ! \n");
}

struct pizza_operations clam_pizza_pos = {
    .bake = bake_clam_pizza,
    .box = box_clam_pizza,
    .cut = cut_clam_pizza,
    .prepare = prepare_clam_pizza,
};

void init_clam_pizza(struct clam_pizza *clam_pizza)
{
    init_pizza(&clam_pizza->pizza);
    clam_pizza->pizza.name = "Clam_Pizza";
    clam_pizza->pizza.pos = &clam_pizza_pos;
}