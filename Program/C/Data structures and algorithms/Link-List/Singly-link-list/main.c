#include "single_list.h"

int main(int argc, const char *grav[])
{
	struct node *root = init_list();
	add_head(root, 3);
	add_head(root, 2);
	add_head(root, 4);
	print_list(root);
	bubble_sort(root);
	print_list(root);
	return 0;
}
