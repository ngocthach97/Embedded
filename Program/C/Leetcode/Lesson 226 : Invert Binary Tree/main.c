#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int num;
    struct Node *left;
    struct Node *right;
};

int countNodeInTree(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countNodeInTree(root->left) + countNodeInTree(root->right);
}

struct Node *initNode(int num)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->left = NULL;
    node->right = NULL;
    node->num = num;
    return node;
}

struct Node *addElementInTree(struct Node *root, int num)
{
    struct Node *p = root;
    struct Node *q;
    struct Node *new = initNode(num);
    if (root == NULL)
    {
        root = new;
        return new;
    }
    while (1)
    {
        q = p;
        if (p->num > num)
        {
            p = p->left;
            if (p == NULL)
            {
                q->left = new;
                return root;
            }
        }
        else
        {
            p = p->right;
            if (p == NULL)
            {
                q->right = new;
                return root;
            }
        }
    }
}

void deleteElementInTree(struct Node *root, int num)
{
    
}

struct Node *findElementInTree(struct Node *root, int num)
{
    struct Node *node = root;
    while (node != NULL)
    {
        if (node->num > num)
        {
            node = node->left;
        }
        else if (node->num < num)
        {
            node = node->right;
        }
        else
        {
            return node;
        }
    }
}

void invertTree(struct Node *root)
{
}

void inorderTraversal(struct Node *root)
{
}

void preorderTraversal(struct Node *root)
{
}

void postorderTraversal(struct Node *root)
{
}

int main(int agrv, const char *argc[])
{
    struct Node *root = NULL;
    root = addElementInTree(root, 3);
    addElementInTree(root, 2);
    addElementInTree(root, 5);
    struct Node *node = findElementInTree(root, 5);
    printf("%d", node->num);
    printf("%d", countNodeInTree(root));
    return 0;
}