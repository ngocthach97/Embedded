#ifndef PIZZA_H_
#define PIZZA_H_

struct chain_handle_operations;

struct chain_handle
{
    struct chain_handle_operations *ops;
    struct chain_handle *next;
};

struct chain_handle_operations
{
    void (*_add_node)(struct chain_handle *, struct chain_handle *next);
    void (*_handle_node)(struct chain_handle *);
};

void init_chain_handle(struct chain_handle *);

static inline void add_chain(struct chain_handle *current, struct chain_handle *next)
{
    current->ops->_add_node(current, next);
}

static inline void handle_chain(struct chain_handle *current)
{
    current->ops->_handle_node(current);
}

#endif