#include <stdio.h>
#include <stdlib.h>
#include "RoundedSquare.h"

void draw_roundedSquare(struct shape *shape)
{
    printf("Draw rounded square \n");
}
void free_roundedSquare(struct shape *shape)
{
    printf("Free rounded square \n");
}

struct shape_operations roundedSquare_ops = {
    .draw = draw_roundedSquare,
    .free = free_roundedSquare,
};

void init_roundedSquare(struct roundedSquare *roundedSquare)
{
    init_shape(&roundedSquare->shape);
    roundedSquare->shape.ops = &roundedSquare_ops;
}