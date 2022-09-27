#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
struct TreeNode
{
    int num;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *initTreeNode(int num)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->left = NULL;
    node->right = NULL;
    node->num = num;
    return node;
}

struct Node
{
    int num;
    struct Node *next;
};

int lengthList(struct Node *root)
{
    struct Node *p = root;
    int length = 0;
    while (1)
    {
        if (p->next == NULL)
        {
            return length;
        }
        length++;
        p = p->next;
    }
}

void printList(struct Node *root)
{
    struct Node *p = root;
    if (p->next == NULL)
    {
        printf("list empty ! \n");
    }
    while (p->next != NULL)
    {
        printf("value = %d \n", p->next->num);
        p = p->next;
    }
}

struct Node *initNode(int num)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->num = num;
    node->next = NULL;
    return node;
}

bool emptyList(struct Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    return false;
}

void addElementFirst(struct Node *root, int num)
{
    struct Node *node = initNode(num);
    if (root->next != NULL)
    {
        node->next = root->next;
    }
    root->next = node;
}

void addElementLast(struct Node *root, int num)
{
    struct Node *node = initNode(num);
    struct Node *p = root->next;
    if (p == NULL)
    {
        root->next = node;
    }
    while (p != NULL)
    {
        if (p->next == NULL)
        {
            p->next = node;
            break;
        }
        p = p->next;
    }
}

int findElementList(struct Node *root, int target)
{
    int position = 0;
    struct Node *p = root->next;
    while (p != NULL)
    {
        position++;
        if (p->num == target)
        {
            return position;
        }
        p = p->next;
    }
    return 0;
}

void addElementPosition(struct Node *root, int position, int num)
{
    int length = lengthList(root);
    if (position == 0)
    {
        addElementFirst(root, num);
    }
    else if (position == length)
    {
        addElementLast(root, num);
    }
    else if (position > length)
    {
        printf("Cannot add element in list ! \n");
    }
    else
    {
        struct Node *node = initNode(num);
        struct Node *p = root->next;
        struct Node *q = NULL;
        for (int i = 0; i < position - 1; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = node;
        node->next = q;
    }
}

void sortList(struct Node *root)
{
    int length = lengthList(root);
    int a;
    for (int i = 0; i < length - 1; i++)
    {
        struct Node *p = root->next;
        struct Node *q = NULL;
        for (int j = length - 1; j > 0; j--)
        {
            q = p->next;
            if (q != NULL)
            {
                if (q->num < p->num)
                {
                    a = q->num;
                    q->num = p->num;
                    p->num = a;
                }
                p = p->next;
            }
        }
    }
}

bool palindromeList(struct Node *root)
{
    int size = lengthList(root);
    int stack[size];
    int a = 0;
    struct Node *node = root->next;
    while (node != NULL)
    {
        stack[size - 1 - a] = node->num;
        a++;
        node = node->next;
    }
    node = root->next;
    while (node != NULL)
    {
        if (stack[size - a] != node->num)
        {
            return false;
        }
        a--;
        node = node->next;
    }
    return true;
}

void rotateList(struct Node *root)
{
    struct Node *node = root->next;
    int size = lengthList(root);
    int stack[size];
    int a = 0;
    while (node != NULL)
    {
        stack[size - 1 - a] = node->num;
        a++;
        node = node->next;
    }
    node = root->next;
    while (node != NULL)
    {
        node->num = stack[size - a];
        a--;
        node = node->next;
    }
}

struct Node *reverseList(struct Node *root)
{
    struct Node *p = root->next;
    struct Node *q = NULL;
    struct Node *r = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        q->next = r;
        r = q;
    }
    root->next = r;
    return root;
}

void reorderList(struct Node *root)
{
    struct Node *node = root->next;
    int size = lengthList(root);
    int a = 1;
    int b = 0;
    int c = size - 1;
    int d = 0;
    int queue[size];
    while (node != NULL)
    {
        queue[size - a] = node->num;
        a++;
        node = node->next;
    }
    node = root->next;
    while (node != NULL)
    {
        if ((d % 2) == 0)
        {
            node->num = queue[size - 1 - b];
            b++;
        }
        else
        {
            node->num = queue[size - 1 - c];
            c--;
        }
        d++;
        node = node->next;
    }
}

void deleteElementFirst(struct Node *root)
{
    struct Node *node = root->next;
    if (node == NULL)
    {
        printf("List empty !\n");
    }
    else
    {
        root->next = node->next;
        node->next = NULL;
        free(node);
    }
}

void deleteElementLast(struct Node *root)
{
    struct Node *node = root->next;
    struct Node *run;
    if (node == NULL)
    {
        printf("List empty !\n");
    }
    else
    {
        while (node->next != NULL)
        {
            run = node;
            node = node->next;
        }
        run->next = NULL;
        free(node);
    }
}

void deleteElementPosition(struct Node *root, int num)
{
    struct Node *node = root->next;
    if (node == NULL)
    {
        printf("Cannot delete element in list ! \n");
    }
    struct Node *run = NULL;
    int count = 1;
    int length = lengthList(root);
    while (node->num != num)
    {

        run = node;
        node = node->next;
        if (node == NULL)
        {
            count++;
            break;
        }
        count++;
    }
    if (count == 1)
    {
        deleteElementFirst(root);
    }
    else if (count == length)
    {
        deleteElementLast(root);
    }
    else if (count > length)
    {
        printf("Cannot delete element in list ! \n");
    }
    else
    {
        run->next = node->next;
        node->next = NULL;
        free(node);
    }
}

void swapNodes(struct Node *root, int k)
{
    struct Node *node = root->next;
    struct Node *run;
    int length = lengthList(root);
    int position = length - (k + 1);
    if (position > k)
    {
        for (int i = 0; i < position; i++)
        {
            if (i == k)
            {
                run = node;
            }
            node = node->next;
        }
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            if (i == position)
            {
                run = node;
            }
            node = node->next;
        }
    }
    int bridge = run->num;
    run->num = node->num;
    node->num = bridge;
}

// Odd Even Linked List
// void oddEvenList(struct Node *root)
// {

// }

// Intersection of Two Linked Lists
// void getIntersectionNode(struct Node *root1, struct Node *root2)
// {
// }

struct Node *getNodeLastInList(struct Node *root)
{
    struct Node *node = root->next;
    while (node->next != NULL)
    {
        node = node->next;
    }
    return node;
}

// Middle of the Linked List
struct Node *getNodeMiddleInList(struct Node *root, int start, int end)
{
    struct Node *node = root->next;
    int length = (end - start) + 1;
    if (node != NULL)
    {
        if (end >= 0 && start >= 0 && end >= start)
        {

            int middle = (length / 2);
            printf("%d \n", middle);
            if (start > 0)
            {
                for (int i = 0; i < start; i++)
                {
                    node = node->next;
                }
            }
            while (middle--)
            {
                node = node->next;
            }

            return node;
        }
    }
    return NULL;
}
// Convert Sorted List to Binary Search Tree
// struct TreeNode* sortedListToBST(struct ListNode* root){

// }

// Convert Binary Number in a Linked List to Integer
int getDecimalValue(struct Node *root)
{
    struct Node *node = root->next;
    int length = lengthList(root);
    int decimal = 0;
    for (int i = 0; i < length; i++)
    {
        int a = (int)pow(2, i);
        decimal += (node->num) * a;
        node = node->next;
    }
    return decimal;
}

// Merge Two Sorted Lists
struct ListNode *mergeTwoLists(struct Node *root1, struct Node *root2)
{
}

// Split Linked List in Parts
struct ListNode **splitListToParts(struct Node *root, int k, int *returnSize)
{
    int length = lengthList(root);
    if (length >= k)
    {
    }
    else
    {
    }
}

int main(int agrv, const char *argc[])
{
    struct Node *root1 = (struct Node *)malloc(sizeof(struct Node));
    addElementFirst(root1, 1);
    addElementFirst(root1, 0);
    addElementFirst(root1, 0);
    addElementFirst(root1, 1);
    addElementFirst(root1, 1);
    printList(root1);
    printf("%d", getDecimalValue(root1));

    return 0;
}
