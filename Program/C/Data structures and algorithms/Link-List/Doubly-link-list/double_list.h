#ifndef DOUBLE_LIST_
#define DOUBLE_LIST_
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *init_list();

struct node *init_node(int data);

int length_list(struct node *root);

bool isEmpty(struct node *root);

void print_list(struct node *root);

void add_node_head(struct node *root, int data);

void add_node_tail(struct node *root, int data);

void add_node_position(struct node *root, int data, int position);

void delete_node_head(struct node *root);

void delete_node_tail(struct node *root);

void delete_node_position(struct node *root, int position);

#endif