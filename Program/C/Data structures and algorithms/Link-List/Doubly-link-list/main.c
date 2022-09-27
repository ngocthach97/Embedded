#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "double_list.h"

int main(int argc, const char *argv[])
{
	struct node *root = init_list();
	add_node_head(root, 1);
	add_node_head(root, 2);
	add_node_head(root, 3);
	add_node_head(root, 4);
	add_node_head(root, 5);
	delete_node_position(root, 2);
	print_list(root);
	return 0;
}
