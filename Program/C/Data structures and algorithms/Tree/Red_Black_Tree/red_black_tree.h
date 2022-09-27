#ifndef RED_BLACK_TREE_
#define RED_BLACK_TREE_

enum COLOR
{
    RED,
    BLACK,
};

struct node
{
    enum COLOR color;
    struct node *left;
    struct node *right;
};

struct root
{
    struct node *node;
};

#endif