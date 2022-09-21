#ifndef ABSTRACT_FACTORY_AF_
#define ABSTRACT_FACTORY_AF_
#include "Shape.h"

struct abstractFactory
{
    struct abstractFactory_ops *ops;
};

struct abstractFactory_ops
{
    struct shape *(*getShape)(const char *shapeType);
};

void init_abstractFactory(struct abstractFactory *);

static inline struct shape *get_Shape(struct abstractFactory *abstractFactory, const char *shapeType)
{
    return abstractFactory->ops->getShape(shapeType);
}
#endif