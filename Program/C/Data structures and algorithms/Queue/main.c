#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, const char *grav[])
{
    struct head *root = init_queue();
    printf("%d", enQueue(root, 1));
    printf("%d", enQueue(root, 2));
    printf("%d", root->length);
    return 0;
}
