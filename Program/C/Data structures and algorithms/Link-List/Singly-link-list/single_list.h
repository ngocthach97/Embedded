#ifndef SINGLE_LIST_
#define SINGLE_LIST_
#include <stdbool.h>
struct node
{
    int data;
    struct node *next;
};

struct node *init_node(int data);

struct node *init_list();

void add_head(struct node *root, int data);

void add_tail(struct node *root, int data);

void add_node_position(struct node *root, int position, int data);

int length_list(struct node *root);

bool isEmpty(struct node *root);

bool search_node(struct node *root, int data);

void print_list(struct node *root);

void delete_tail(struct node *root);

void delete_head(struct node *root);

void delete_node_position(struct node *root, int position);

void swap(int value_1, int value_2);

bool linear_search(struct node *root, int data);

bool binary_search(struct node *root, int data);

void bubble_sort(struct node *root);

void partitioning_sort(struct node *root);

void straight_selection_sort(struct node *root);

void straight_insertion_sort(struct node *root);

#endif