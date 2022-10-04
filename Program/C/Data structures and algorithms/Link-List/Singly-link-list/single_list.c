#include "single_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node *init_node(int data)
{
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->data = data;
	n->next = NULL;
	return n;
}

struct node *init_list()
{
	struct node *node = (struct node *)malloc(sizeof(struct node));
	return node;
}

void add_head(struct node *root, int data)
{
	struct node *new = init_node(data);
	struct node *run = root->next;
	if (run != NULL)
	{
		new->next = run;
	}
	root->next = new;
}

void add_tail(struct node *root, int data)
{
	struct node *new = init_node(data);
	struct node *run = root->next;
	struct node *follow;
	if (run == NULL)
	{
		root->next = new;
	}
	else
	{
		while (run != NULL)
		{
			follow = run;
			run = run->next;
		}
		follow->next = new;
	}
}

int length_list(struct node *root)
{
	int length = 0;
	struct node *run = root->next;
	while (run != NULL)
	{
		length++;
		run = run->next;
	}
	return length;
}

bool isEmpty(struct node *root)
{
	struct node *run = root->next;
	if (run == NULL)
	{
		return true;
	}
	return false;
}

bool search_node(struct node *root, int data)
{
	struct node *run = root->next;
	while (run != NULL)
	{
		if (run->data == data)
		{
			return true;
		}
		run = run->next;
	}
	return false;
}

void print_list(struct node *root)
{
	struct node *run = root->next;
	if (run == NULL)
	{
		printf("List empty !\n");
	}
	else
	{
		while (run != NULL)
		{
			printf("%d \n", run->data);
			run = run->next;
		}
	}
}
void add_node_position(struct node *root, int position, int data)
{
	struct node *run = root->next;
	struct node *follow;
	struct node *new = init_node(data);
	int position_last = length_list(root) - 1;
	if (position == 0)
	{
		add_head(root, data);
	}
	else if (position == position_last)
	{
		add_tail(root, data);
	}
	else
	{
		for (int i = 0; i <= position; i++)
		{
			follow = run;
			run = run->next;
		}
		follow->next = new;
		new->next = run;
	}
}
void delete_tail(struct node *root)
{
	struct node *run = root->next;
	struct node *next;
	if (isEmpty(root))
	{
		printf("List empty !\n");
	}
	else
	{
		if (run->next == NULL)
		{
			root->next = NULL;
			free(run);
		}
		else
		{
			while (run->next != NULL)
			{
				next = run;
				run = run->next;
			}
			next->next = NULL;
			free(run);
		}
	}
}

void delete_head(struct node *root)
{
	struct node *run = root->next;
	if (isEmpty(root))
	{
		printf("List empty !\n");
	}
	else
	{
		root->next = run->next;
		run->next = NULL;
		free(run);
	}
}

void delete_node_position(struct node *root, int position)
{
	struct node *run = root->next;
	struct node *follow;
	int length = length_list(root);
	int position_last = length - 1;
	if (position == 0)
	{
		delete_head(root);
	}
	else if (position == position_last)
	{
		delete_tail(root);
	}
	else
	{
		for (int i = 0; i < position; i++)
		{
			follow = run;
			run = run->next;
		}
		follow->next = run->next;
		run->next = NULL;
		free(run);
	}
}

struct node *get_tail(struct node *root)
{
	int length = length_list(root);
	struct node *run = root->next;
	for (int i = 0; i < length - 1; i++)
	{
		run = run->next;
	}
	return run;
}

bool linear_search(struct node *root, int data)
{
	struct node *run = root->next;
	int length = length_list(root);
	for (int i = 0; i < length - 1; i++)
	{
		if (run->data == data)
		{
			return true;
		}
		run = run->next;
	}
	return false;
}

void bubble_sort(struct node *root)
{
	int length = length_list(root);
	for (int i = 0; i < length - 1; i++)
	{
		struct node *node = root->next;
		struct node *run;
		for (int j = length - 1; j > 0; j--)
		{
			run = node->next;
			if (run != NULL)
			{
				if (node->data > run->data)
				{
					int a = node->data;
					node->data = run->data;
					run->data = a;
				}
				node = node->next;
			}
		}
	}
}

void swapPairs(struct node *root)
{
	struct node *run = root->next;
	struct node *node;
	while (run->next != NULL)
	{
		node = run->next;
		int a = run->data;
		run->data = node->data;
		node->data = a;
		if (node->next == NULL)
		{
			break;
		}
		else
		{
			run = node->next;
		}
	}
}

void reverseKGroup(struct node *root, int k)
{
	struct node *run = root->next;
	struct node *node;
	int length = length_list(root);
	int count = length / k;
	for (int i = 0; i < count; i++)
	{
		node = run;
		int stack[k];
		for (int j = 0; j < k; j++)
		{
			stack[j] = run->data;
			run = run->next;
		}
		for (int h = k - 1; h >= 0; h--)
		{
			node->data = stack[h];
			node = node->next;
		}
	}
}

struct node *partition(struct node *root, int x)
{
	struct node *run = root->next;
	struct node *before = init_list();
	struct node *after = init_list();
	while (run != NULL)
	{
		if (run->data < x)
		{
			add_tail(after, run->data);
		}
		else
		{
			add_tail(before, run->data);
		}
		run = run->next;
	}
	struct node *tail = get_tail(after);
	tail->next = before->next;
	return after;
}

struct node *oddEvenList(struct node *root)
{
	struct node *run = root->next;
	struct node *odd = init_list();
	struct node *even = init_list();
	int index = 0;
	while (run != NULL)
	{
		int value = index % 2;
		if (value == 0)
		{
			add_tail(even, run->data);
		}
		else
		{
			add_tail(odd, run->data);
		}
		index++;
		run = run->next;
	}
	struct node *tail = get_tail(odd);
	tail->next = even->next;
	return odd;
}

struct node *mergeTwoLists(struct node *list1, struct node *list2)
{
	struct node *run1 = list1->next;
	struct node *run2 = list2->next;
	struct node *merge = init_list();
	while (1)
	{
		if (run1 == NULL && run2 == NULL)
		{
			break;
		}
		else if (run1 != NULL && run2 == NULL)
		{
			add_tail(merge, run1->data);
			run1 = run1->next;
		}
		else if (run1 == NULL && run2 != NULL)
		{
			add_tail(merge, run2->data);
			run2 = run2->next;
		}
		else
		{
			if (run1->data > run2->data)
			{
				add_tail(merge, run2->data);
				run2 = run2->next;
			}
			else
			{
				add_tail(merge, run1->data);
				run1 = run1->next;
			}
		}
	}
	return merge;
}