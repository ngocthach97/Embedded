#ifndef ROUNDED_SHAPEFACTORY_AF_
#define ROUNDED_SHAPEFACTORY_AF_
#include "AbstractFactory.h"
#include "Shape.h"

struct roundedShapeFactory
{
    struct abstractFactory abstractFactory;
};

void init_roundedShapeFactory(struct roundedShapeFactory *);

#endif