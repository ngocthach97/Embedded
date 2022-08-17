#include "chain_handle1.h"
#include <stdio.h>
#include "chain_handle.h"

void add_node_1(struct chain_handle *chain_handle, struct chain_handle *next)
{
    if (chain_handle->next)
        add_chain(chain_handle->next, next);
    else
        chain_handle->next = next;    
}

void handle_node_1(struct chain_handle *chain_handle)
{
    printf("handle node 1 !\n");
}

struct chain_handle_operations chain_handle1_ops = {
    ._add_node = add_node_1,
    ._handle_node = handle_node_1,
};

void init_chain_handle1(struct chain_handle1 *chain_handle1)
{
    init_chain_handle(&chain_handle1->chain_handle);
    chain_handle1->chain_handle.ops = &chain_handle1_ops;
}