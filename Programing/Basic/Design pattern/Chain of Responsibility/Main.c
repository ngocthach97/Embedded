#include <stdio.h>
#include <stdlib.h>
#include "chain_handle.h"
#include "chain_handle1.h"
#include "chain_handle2.h"
#include "chain_handle3.h"

int main(int argc, const char *argv[])
{
    struct chain_handle *root = (struct chain_handle *)malloc(sizeof(struct chain_handle));

    struct chain_handle1 *handle1 = (struct chain_handle1 *)malloc(sizeof(struct chain_handle1));

    struct chain_handle2 *handle2 = (struct chain_handle2 *)malloc(sizeof(struct chain_handle2));

    struct chain_handle3 *handle3 = (struct chain_handle3 *)malloc(sizeof(struct chain_handle3));

    init_chain_handle1(handle1);

    init_chain_handle2(handle2);

    init_chain_handle3(handle3);

    add_chain(&handle1->chain_handle, &handle2->chain_handle);

    add_chain(&handle2->chain_handle, &handle3->chain_handle);

    root = &handle1->chain_handle;
    while (root != NULL)
    {
        handle_chain(root);
        root = root->next;
    }
    return 0;
}