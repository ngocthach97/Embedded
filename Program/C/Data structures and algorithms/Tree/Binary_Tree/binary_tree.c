#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct node *init_tree()
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node *initNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void add_node(struct node *root, int data)
{
    struct node *new = initNode(data);
    struct node *run = root->right;
    struct node *follow;
    if (root->right == NULL)
    {
        root->right = new;
    }
    else
    {
        while (1)
        {
            follow = run;
            if (run->data > data)
            {
                run = run->left;
                if (run == NULL)
                {
                    follow->left = new;
                    break;
                }
            }
            else
            {
                run = run->right;
                if (run == NULL)
                {
                    follow->right = new;
                    break;
                }
            }
        }
    }
}

bool search_node(struct node *root, int data)
{
    struct node *node = root->right;
    if (node == NULL)
    {
        printf("tree empty !\n");
    }
    else
    {
        while (node != NULL)
        {
            if (node->data > data)
            {
                if (node->data == data)
                {
                    return true;
                }
                node = node->left;
            }
            else
            {
                if (node->data == data)
                {
                    return true;
                }
                node = node->right;
            }
        }
    }
    return false;
}