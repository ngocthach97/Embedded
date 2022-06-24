#include "Veggie_Pizza.h"
#include "Pizza.h"
#include <stdio.h>

void bake_veggie_pizza(struct pizza *pizza)
{
    printf("Bake veggie pizza ! \n");
}

void box_veggie_pizza(struct pizza *pizza)
{
    printf("Box veggie pizza ! \n");
}

void cut_veggie_pizza(struct pizza *pizza)
{
    printf("Cut veggie pizza ! \n");
}

void prepare_veggie_pizza(struct pizza *pizza)
{
    printf("Prepare veggie pizza ! \n");
}

struct pizza_operations veggie_pizza_pos = {
    .bake = bake_veggie_pizza,
    .box = box_veggie_pizza,
    .cut = cut_veggie_pizza,
    .prepare = prepare_veggie_pizza,
};

void init_veggie_pizza(struct veggie_pizza *veggie_pizza)
{
    init_pizza(&veggie_pizza->pizza);
    veggie_pizza->pizza.name = "Veggie Pizza";
    veggie_pizza->pizza.pos = &veggie_pizza_pos;
}