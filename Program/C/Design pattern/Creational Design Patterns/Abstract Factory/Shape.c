#include <stdio.h>
#include <stdlib.h>
#include "Shape.h"


void init_shape(struct shape *shape){
    shape->ops = NULL;
}