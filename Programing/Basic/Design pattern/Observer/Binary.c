#include "Binary.h"
#include <stdio.h>
#include "Subject.h"
#include "Observer.h"

void binary_update(struct observer *observer)
{
    printf("binary update ! \n");
}

struct observer_pos binary_ops = {
    .update = binary_update,
};

void init_binary(struct binary *binary)
{
    init_observer(&binary->observer);
    binary->observer.pos = &binary_ops;
}