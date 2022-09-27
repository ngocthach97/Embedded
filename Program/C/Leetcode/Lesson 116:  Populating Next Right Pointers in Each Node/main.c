#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

struct Node *init_Node(int num)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
    node->num = num;
    return node;
}
void insertNode (struct Node ** root, int num){

}

int main(int agrv, const char *argc[])
{
    return 0;
}