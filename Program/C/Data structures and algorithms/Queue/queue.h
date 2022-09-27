#ifndef QUEUE_
#define QUEUE_
#include <pthread.h>
#include <stdbool.h>

#define MAX_QUEUE 20

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct head
{
    int length;
    struct node *prev;
    struct node *next;
    pthread_mutex_t lock;
};

struct head *init_queue();

struct node *init_node(int data);

bool isEmpty(struct head *);

bool isFull(struct head *);

bool enQueue(struct head *, int data);

bool deQueue(struct head *);

int peek(struct head *);

#endif