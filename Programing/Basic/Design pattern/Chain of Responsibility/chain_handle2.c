#include "chain_handle2.h"
#include <stdio.h>

void handle_node_2(struct chain_handle *chain_handle)
{
    printf("Handle node 2 !\n");
}

struct chain_handle_operations chain_handle2_ops = {
    ._handle_node = handle_node_2,
};

void init_chain_handle2(struct chain_handle2 *chain_handle2)
{
    init_chain_handle(&chain_handle2->chain_handle);
    chain_handle2->chain_handle.ops = &chain_handle2_ops;
}