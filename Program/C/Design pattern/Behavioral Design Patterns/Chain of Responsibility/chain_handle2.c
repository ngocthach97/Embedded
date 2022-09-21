#include "chain_handle2.h"
#include <stdio.h>

#include "chain_handle.h"
void add_node_2(struct chain_handle *chain_handle, struct chain_handle *next)
{
    if (chain_handle->next)
        add_chain(chain_handle->next, next);
    else
        chain_handle->next = next;    
}

void handle_node_2(struct chain_handle *chain_handle)
{
    printf("Handle node 2 !\n");
}

struct chain_handle_operations chain_handle2_ops = {
    ._add_node = add_node_2,
    ._handle_node = handle_node_2,
};

void init_chain_handle2(struct chain_handle2 *chain_handle2)
{
    init_chain_handle(&chain_handle2->chain_handle);
    chain_handle2->chain_handle.ops = &chain_handle2_ops;
}