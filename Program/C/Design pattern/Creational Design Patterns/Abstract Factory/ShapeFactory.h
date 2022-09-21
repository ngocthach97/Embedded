#ifndef SHAPE_FACTORY_AF_
#define SHAPE_FACTORY_AF_
#include "AbstractFactory.h"
#include "Shape.h"

struct shapeFactory
{
    struct abstractFactory abstractFactory;
};

void init_shapeFactory(struct shapeFactory *);

#endif