#include "Component.h"
#include <stdlib.h>
#include <stdio.h>
void init_component(struct component *component)
{
    component->name = NULL;
    component->pos = NULL;
    component->index = 0;
}

void add_component(struct component *component, struct component *children)
{
    component->children[component->index++] = children;
}

void get_component(struct component *component){
    for (int i = 0; i < component->index; i++)
    {
        printf("component %d \n",i);
    }
}