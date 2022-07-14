#include "chain_handle3.h"
#include <stdio.h>
#include "chain_handle.h"

void add_node_3(struct chain_handle *chain_handle, struct chain_handle *next)
{
    if (chain_handle->next)
        add_chain(chain_handle->next, next);
    else
        chain_handle->next = next;    
}

void handle_node_3(struct chain_handle *chain_handle)
{
    printf("Handle node 3 !\n");
}

struct chain_handle_operations chain_handle3_ops = {
    ._add_node = add_node_3,
    ._handle_node = handle_node_3,
};

void init_chain_handle3(struct chain_handle3 *chain_handle3)
{
    init_chain_handle(&chain_handle3->chain_handle);
    chain_handle3->chain_handle.ops = &chain_handle3_ops;
}