#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
	int data;
	struct node *left;
	struct node *right;
};

struct Node *initNode(int data)
{
	struct Node *n = (struct Node *)malloc(sizeof(struct Node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void addElementInTree(struct Node *root, int data)
{
}

bool searchElementInTree(struct Node *root, int data)
{

}

int main(int argc, const char *argv[])
{
	return 0;
}
