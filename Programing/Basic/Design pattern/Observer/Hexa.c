#include "Hexa.h"
#include <stdio.h>
#include "Subject.h"
#include "Observer.h"

void hexa_update(struct observer *observer)
{
    printf("hexa update ! \n");
}

struct observer_pos hexa_ops = {
    .update = hexa_update,
};

void init_hexa(struct hexa *hexa)
{
    init_observer(&hexa->observer);
    hexa->observer.pos = &hexa_ops;
}