#ifndef SHAPE_CACHE_PROTOTYPE
#define SHAPE_CACHE_PROTOTYPE
#include "Shape.h"

#define SIZE 32

struct shape_cache
{
    int index;
    struct shape *list_shape[SIZE];
};

void init_shape_cache(struct shape_cache *);

struct shape *get_shape(struct shape_cache *, int ID);

void load_cache(struct shape_cache *);

#endif