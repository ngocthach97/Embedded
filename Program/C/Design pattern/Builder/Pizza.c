
#include <string.h> 
#include <stdio.h>
#include "Pizza.h"

void init_pizza(struct pizza *pizza)
{
	pizza->ops = NULL;
	pizza->name = NULL;
}