#include "Octal.h"
#include <stdio.h>
#include "Subject.h"
#include "Observer.h"

void octal_update(struct observer *observer)
{
    printf("octal update ! \n");
}

struct observer_pos octal_ops = {
    .update = octal_update,
};

void init_octal(struct octal *octal)
{
    init_observer(&octal->observer);
    octal->observer.pos = &octal_ops;
}