#include "chain_handle.h"
#include <stdlib.h>

void init_chain_handle(struct chain_handle *chain_handle)
{
    chain_handle->next = NULL;
    chain_handle->ops = NULL;
}