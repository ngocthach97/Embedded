#include "chain_handle.h"
#include <stdlib.h>

void add_chain_ops(struct chain_handle *chain_handle, struct chain_handle *next)
{
    if (chain_handle->next)
        add_chain(chain_handle, next);
    else
        chain_handle->next = next;    
}

void handle_chain_ops(struct chain_handle *chain_handle)
{
    if (chain_handle->next)
        handle_chain(chain_handle);
}

struct chain_handle_operations chain_handle_ops = {
    ._add_node = add_chain_ops,
    ._handle_node = handle_chain_ops,
};
void init_chain_handle(struct chain_handle *chain_handle)
{
    chain_handle->next = NULL;
    chain_handle->ops = &chain_handle_ops;
}