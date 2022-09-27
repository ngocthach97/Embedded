#ifndef BINARY_TREE_
#define BINARY_TREE_
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *init_tree();

struct node *initNode(int data);

void add_node(struct node *root, int data);

bool search_node(struct node *root, int data);

#endif