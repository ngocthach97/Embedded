#include <stdlib.h>
#include <stdio.h> 
#include "CheesePizza.h"

static void cheese_prepare(struct pizza *pizza)
{
	printf("cheese::prepare(%s)\n", pizza->name);
}

static void cheese_bake(struct pizza *pizza)
{
	printf("cheese::bake(%s)\n", pizza->name);
}

static void cheese_cut(struct pizza *pizza)
{
	printf("cheese::cut(%s)\n", pizza->name);
}

static void cheese_box(struct pizza *pizza)
{
	printf("cheese::box(%s)\n", pizza->name);
}

static struct pizza_ops cheese_pizza_ops = {
	.prepare = cheese_prepare,
	.bake = cheese_bake,
	.cut = cheese_cut,
	.box = cheese_box,
};

void init_cheese_pizza(struct cheese_pizza *cheese)
{
	pizza_init(&cheese->pizza);
	cheese->pizza.ops = &cheese_pizza_ops ;
    cheese->pizza.name = "cheese";
}