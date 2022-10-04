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

void add_head(struct node *, int data);

void add_tail(struct node *, int data);

void add_node_position(struct node *, int position, int data);

int length_list(struct node *);

bool isEmpty(struct node *);

bool search_node(struct node *, int data);

void print_list(struct node *);

void delete_tail(struct node *);

void delete_head(struct node *);

void delete_node_position(struct node *, int position);

struct node *get_tail(struct node *);

bool linear_search(struct node *, int data);

bool binary_search(struct node *, int data);

void bubble_sort(struct node *);

void partitioning_sort(struct node *);

void straight_selection_sort(struct node *);

void straight_insertion_sort(struct node *);

void swapPairs(struct node *);

void reverseKGroup(struct node *, int k);

struct node *partition(struct node *, int x);

struct node *oddEvenList(struct node *);

struct node* mergeTwoLists(struct node* , struct node* );

#endif