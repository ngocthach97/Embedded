#include <stdio.h>
#include <stdlib.h>
#include "Maker_Pizza.h"

int main(int argc, const char *crgv[])
{
    struct maker_pizza *maker = (struct maker_pizza *)malloc(sizeof(struct maker_pizza));
    init_maker_pizza(maker);
    cut_cheese_pizza_maker(maker);
    return 0;
}




























