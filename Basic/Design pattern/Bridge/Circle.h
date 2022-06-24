#ifndef CIRCLE_
#define CIRCLE_
#include "Shape.h"

struct circle
{
    struct shape shape;
};

void init_circle(struct circle *,struct color*);

#endif