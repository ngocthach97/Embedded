#include <stdio.h>
#include <stdlib.h>
#include "ShapeCache.h"
int main(int argc, const char *argv[])
{
    struct shape_cache *shape_cache = (struct shape_cache *)malloc(sizeof(struct shape_cache));
    init_shape_cache(shape_cache);
    load_cache(shape_cache);
    struct shape *shape = get_shape(shape_cache, 1);
    printf("%s ! \n", get_type(shape));
    return 0;
}