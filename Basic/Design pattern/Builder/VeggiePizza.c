#include "VeggiePizza.h"

void prepare_veggie(struct pizza *pizza)
{
    printf("Prepare veggie ! \n");
}

void bake_veggie(struct pizza *pizza)
{
    printf("Bake veggie ! \n");
}

void cut_veggie(struct pizza *pizza)
{
    printf("Cut veggie ! \n");
}

void box_veggie(struct pizza *pizza)
{
    printf("Box veggie ! \n");
}

struct pizza_ops veggie_pizza_ops = {
    .prepare = prepare_veggie,
    .bake = bake_veggie,
    .cut = cut_veggie,
    .box = box_veggie,
};

void init_veggie_pizza(struct veggie_pizza *veggie_pizza)
{
    init_pizza(&veggie_pizza->pizza);
    veggie_pizza->pizza.ops = &veggie_pizza_ops;
    veggie_pizza->pizza.name = "veggie";
}