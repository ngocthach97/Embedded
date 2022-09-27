#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_tree.h"

int main(int argc, const char *argv[])
{
	struct node *root = init_tree();
	add_node(root, 2);
	add_node(root, 1);
	add_node(root, 3);
	return 0;
}
