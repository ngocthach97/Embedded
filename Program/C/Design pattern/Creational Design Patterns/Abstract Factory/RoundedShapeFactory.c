#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RoundedSquare.h"
#include "RoundedRectangle.h"
#include "RoundedShapeFactory.h"

struct shape *getShapeInRoundedShapeFactory(const char *shapeType)
{
    struct shape *shape = NULL;
    struct roundedSquare *roundedSquare;
    struct roundedRectangle *roundedRectangle;
    if (strcmp(shapeType, "roundedSquare") == 0)
    {
        roundedSquare = (struct roundedSquare *)malloc(sizeof(struct roundedSquare));
        if (roundedSquare == NULL)
        {
            return NULL;
        }
        init_roundedSquare(roundedSquare);
        shape = &roundedSquare->shape;
    }
    else if (strcmp(shapeType, "roundedRectangle") == 0)
    {
        roundedRectangle = (struct roundedRectangle *)malloc(sizeof(struct roundedRectangle));
        if (roundedRectangle == NULL)
        {
            return NULL;
        }
        init_roundedRectangle(roundedRectangle);
        shape = &roundedRectangle->shape;
    }
    return shape;
}
struct abstractFactory_ops roundedShapeFactory_ops = {
    .getShape = getShapeInRoundedShapeFactory,
};

void init_roundedShapeFactory(struct roundedShapeFactory *roundedShapeFactory)
{
    init_abstractFactory(&roundedShapeFactory->abstractFactory);
    roundedShapeFactory->abstractFactory.ops = &roundedShapeFactory_ops;
}