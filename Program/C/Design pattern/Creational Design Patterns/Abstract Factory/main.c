#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ShapeFactory.h"
#include "RoundedShapeFactory.h"
#include "Shape.h"

int main(int argc, const char *argv[])
{
    bool rounded = true;
    struct shapeFactory *shapeFactory;
    struct roundedShapeFactory *roundedShapeFactory;
    if (rounded == true)
    {
        roundedShapeFactory = (struct roundedShapeFactory *)malloc(sizeof(struct roundedShapeFactory));
        init_roundedShapeFactory(roundedShapeFactory);
        struct shape *shape = get_Shape(&roundedShapeFactory->abstractFactory, "roundedSquare");
        draw_shape(shape);
    }
    else
    {
        shapeFactory = (struct shapeFactory *)malloc(sizeof(struct shapeFactory));
        init_shapeFactory(shapeFactory);
        struct shape *shape = get_Shape(&shapeFactory->abstractFactory, "square");
        draw_shape(shape);
    }
    return 0;
}