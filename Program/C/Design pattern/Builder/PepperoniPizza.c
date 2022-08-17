#include "PepperoniPizza.h"

void prepare_pepperoni(struct pizza *pizza)
{
    printf("Prepare pepperoni ! \n");
}

void bake_pepperoni(struct pizza *pizza)
{
    printf("Bake pepperoni ! \n");
}

void cut_pepperoni(struct pizza *pizza)
{
    printf("Cut pepperoni ! \n");
}

void box_pepperoni(struct pizza *pizza)
{
    printf("Box pepperoni ! \n");
}

struct pizza_ops pepperoni_pizza_pos = {
    .prepare = prepare_pepperoni,
    .bake = bake_pepperoni,
    .cut = cut_pepperoni,
    .box = box_pepperoni,
};

void init_pepperoni_pizza(struct pepperoni_pizza *pepperoni)
{
    init_pizza(&pepperoni->pizza);
    pepperoni->pizza.ops = &pepperoni_pizza_pos;
    pepperoni->pizza.name = "pepperoni";
}