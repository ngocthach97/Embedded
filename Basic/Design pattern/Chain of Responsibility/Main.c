#include <stdio.h>
#include <stdlib.h>
#include "chain_handle.h"
#include "chain_handle1.h"
#include "chain_handle2.h"

int main(int argc, const char *argv[])
{
    struct chain_handle1 *handle1 = (struct chain_handle1 *)malloc(sizeof(struct chain_handle1));

    struct chain_handle2 *handle2 = (struct chain_handle2 *)malloc(sizeof(struct chain_handle2));

    init_chain_handle1(handle1);

    init_chain_handle2(handle2);

    add_chain(&handle1->chain_handle, &handle2->chain_handle);

    handle_chain(&handle1->chain_handle);

    return 0;
}