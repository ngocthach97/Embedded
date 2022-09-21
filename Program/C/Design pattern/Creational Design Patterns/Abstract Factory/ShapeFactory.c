#include <stdio.h>
#include <stdlib.h>
#include "ShapeFactory.h"
#include "Square.h"
#include "Rectangle.h"
#include <string.h>
struct shape *getShapeInShapeFactory(const char *shapeType)
{
    struct shape *shape = NULL;
    struct square *square;
    struct rectangle *rectangle;
    if (strcmp(shapeType, "square") == 0)
    {
        square = (struct square *)malloc(sizeof(struct square));
        if (square == NULL)
        {
            return NULL;
        }
        init_square(square);
        shape = &square->shape;
    }
    else if (strcmp(shapeType, "rectangle") == 0)
    {
        rectangle = (struct rectangle *)malloc(sizeof(struct rectangle));
        if (rectangle == NULL)
        {
            return NULL;
        }
        init_rectangle(rectangle);
        shape = &rectangle->shape;
    }
    return shape;
}

struct abstractFactory_ops shapeFactory_ops = {
    .getShape = getShapeInShapeFactory,
};

void init_shapeFactory(struct shapeFactory *shapeFactory)
{
    init_abstractFactory(&shapeFactory->abstractFactory);
    shapeFactory->abstractFactory.ops = &shapeFactory_ops;
}