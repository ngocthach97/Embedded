#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct head *init_queue()
{
    struct head *root = (struct head *)malloc(sizeof(struct head));
    root->length = 0;
    root->next = NULL;
    root->prev = NULL;
    int value_mutex = pthread_mutex_init(&root->lock, NULL);
    if (value_mutex != 0)
    {
        return NULL;
    }
    return root;
}

struct node *init_node(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

bool isEmpty(struct head *head)
{
    if (head->next == NULL && head->prev == NULL)
    {
        return true;
    }
    return false;
}

bool isFull(struct head *head)
{
    if (head->length == MAX_QUEUE)
    {
        return true;
    }
    return false;
}

bool enQueue(struct head *head, int data)
{
    int value_lock = pthread_mutex_lock(&head->lock);
    if (value_lock != 0)
    {
        return false;
    }
    struct node *node = init_node(data);
    if (isEmpty(head))
    {
        head->prev = node;
        head->next = node;
        head->length++;
    }
    else
    {
        if (isFull(head))
        {
            return false;
        }
        else
        {
            node->next = head->prev;
            head->prev->prev = node;
            head->prev = node;
            head->length++;
        }
    }
    pthread_mutex_unlock(&head->lock);
    return true;
}