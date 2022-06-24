#include "chain_handle1.h"
#include <stdio.h>

void handle_node_1(struct chain_handle *chain_handle)
{
    printf("Handle node 1 !\n");
}

struct chain_handle_operations chain_handle1_ops = {
    ._handle_node = handle_node_1,
};

void init_chain_handle1(struct chain_handle1 *chain_handle1)
{
    init_chain_handle(&chain_handle1->chain_handle);
    chain_handle1->chain_handle.ops = &chain_handle1_ops;
}