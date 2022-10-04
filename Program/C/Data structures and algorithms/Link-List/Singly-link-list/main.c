#include "single_list.h"
#include <stdio.h>
int main(int argc, const char *grav[])
{
	struct node *root = init_list();
	add_head(root, 10);
	add_head(root, 5);
	add_head(root, 3);
	add_head(root, 2);
	add_head(root, 1);
	add_head(root, 1);
	print_list(root);
	return 0;
}
