#include "Cheese_Pizza.h"
#include "Pizza.h"
#include <stdio.h>

void prepare_cheese_pizza(struct pizza *pizza)
{
    printf("Prepare Cheese Pizza !\n");
};

void bake_cheese_pizza(struct pizza *pizza)
{
    printf("Bake Cheese Pizza!\n");
};

void cut_cheese_pizza(struct pizza *pizza)
{
    printf("Cut Cheese Pizza!\n");
};

void box_cheese_pizza(struct pizza *pizza)
{
    printf("Box Cheese Pizza !\n");
};

struct pizza_operations cheese_pizza_ops =
    {
        .prepare = prepare_cheese_pizza,
        .bake = bake_cheese_pizza,
        .cut = cut_cheese_pizza,
        .box = box_cheese_pizza,
};

void init_cheese_pizza(struct cheese_pizza *cheese_pizza)
{
    init_pizza(&cheese_pizza->pizza);
    cheese_pizza->pizza.name = "Cheese_Pizza";
    cheese_pizza->pizza.pos = &cheese_pizza_ops;
}