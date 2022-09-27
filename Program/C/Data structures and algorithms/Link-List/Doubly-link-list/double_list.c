#include "double_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node *init_list()
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->next = NULL;
    node->prev = NULL;
    return node;
}

struct node *init_node(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

int length_list(struct node *root)
{
    int length = 0;
    struct node *run = root->prev;
    while (run != NULL)
    {
        length++;
        run = run->next;
    }
    return length;
}

bool isEmpty(struct node *root)
{
    if (root->next == NULL && root->prev == NULL)
    {
        return true;
    }
    return false;
}

void print_list(struct node *root)
{
    struct node *run = root->prev;
    if (isEmpty(root))
    {
        printf("list empty !\n");
    }
    else
    {
        while (run != NULL)
        {
            printf("%d \n", run->data);
            run = run->next;
        }
    }
}

void add_node_head(struct node *root, int data)
{
    struct node *new = init_node(data);
    if (isEmpty(root))
    {
        root->prev = new;
        root->next = new;
    }
    else
    {
        new->next = root->prev;
        root->prev->prev = new;
        root->prev = new;
    }
}

void add_node_tail(struct node *root, int data)
{
    struct node *new = init_node(data);
    if (isEmpty(root))
    {
        root->next = new;
        root->prev = new;
    }
    else
    {
        root->next->next = new;
        new->prev = root->next;
        root->next = new;
    }
}

void add_node_position(struct node *root, int data, int position)
{
    struct node *new = init_node(data);
    struct node *follow;
    struct node *run = root->prev;
    int position_last = length_list(root) - 1;
    if (position == 0)
    {
        add_node_head(root, data);
    }
    else if (position == position_last)
    {
        add_node_tail(root, data);
    }
    else
    {
        for (int i = 0; i <= position; i++)
        {
            follow = run;
            run = run->next;
        }
        follow->next = new;
        new->prev = follow;
        new->next = run;
        run->prev = new;
    }
}

void delete_node_head(struct node *root)
{
    if (isEmpty(root))
    {
        printf("list empty !\n");
    }
    else
    {
        if (root->prev == root->next)
        {
            root->prev = root->next = NULL;
        }
        else
        {
            root->prev = root->prev->next;
            free(root->prev->prev);
        }
    }
}

void delete_node_tail(struct node *root)
{
    if (isEmpty(root))
    {
        printf("list empty !\n");
    }
    else
    {
        if (root->next == root->prev)
        {
            root->next = root->prev = NULL;
        }
        else
        {
            root->next = root->next->prev;
            free(root->next->next);
        }
    }
}

void delete_node_position(struct node *root, int position)
{
    struct node *run = root->prev;
    struct node *follow;
    int position_last = length_list(root) - 1;
    if (isEmpty(root))
    {
        printf("list empty !\n");
    }
    else
    {
        if (position == 0)
        {
            delete_node_head(root);
        }
        else if (position == position_last)
        {
            delete_node_tail(root);
        }
        else
        {
            for (int i = 0; i < position; i++)
            {
                follow = run;
                run = run->next;
            }
            follow->next = run->next;
            run->next->prev = follow;
            free(run);
        }
    }
}