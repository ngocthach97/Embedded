#include <stdio.h>
#include <stdlib.h>
#include "AbstractFactory.h"

void init_abstractFactory(struct abstractFactory *abstractFactory)
{
    abstractFactory->ops = NULL;
}