#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head = NULL;

struct node *tail = NULL;

struct node *init_node(int data)
{
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->data = data;
	n->next = NULL;
	return n;
}

void add_head(struct node *n)
{
	if (head == NULL)
	{
		head = n;
		tail = n;
	}
	else
	{
		n->next = head;
		head = n;
	}
}
void add_tail(struct node *n)
{
	if (head == NULL)
	{
		head = n;
		tail = n;
	}
	else
	{
		tail->next = n;
		tail = n;
	}
}

int length(void)
{
	int length = 0;
	struct node *p = head;
	while (p != NULL)
	{
		length++;
		p = p->next;
	}
	return length;
}

bool isEmpty(void)
{
	if (head == NULL && tail == NULL)
	{
		return true;
	}
	return false;
}

bool search_node(int data)
{
	if (head != NULL)
	{
		struct node *p = head;
		while (p != NULL)
		{
			if (p->data == data)
			{
				return true;
			}
			p = p->next;
		}
	}
	return false;
}
void print_list(void)
{
	if (head == NULL)
	{
		printf("list empty !\n");
	}
	else
	{
		struct node *p = head;
		while (p != NULL)
		{
			printf("Data node = %d \n", p->data);
			p = p->next;
		}
	}
}
void delete_node(int data)
{
	if (head != NULL)
	{
		struct node *p = head;
		struct node *q = NULL;
		while (p->data != data)
		{
			if (p->next == NULL)
			{
				return;
			}
			else
			{
				q = p;
				p = p->next;
			}
		}
		if (p == head)
		{
			head = p->next;
			head->next = NULL;
		}
		else
		{
			q->next = p->next;
			p->next = NULL;
			free(p);
		}
	}
}

void delete_tail()
{
	if (head == tail)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		struct node *p = head;
		struct node *q = NULL;
		while (p->next != NULL)
		{
			q = p;
			p = p->next;
		}
		q->next = NULL;
		tail = q;
		free(p);
	}
}
void delete_head()
{
	struct node *p = head;
	if (head == tail)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		head = p->next;
		p->next = NULL;
		free(p);
	}
}
void reverse_list(void)
{
	if (head == tail)
	{
		return;
	}
	else
	{
		struct node *c = head;
		struct node *a = head;
		struct node *b = NULL;
		while (c != NULL)
		{
			c = c->next;
			a->next = b;
			b = a;
			a = c;
		}
		head = tail;
		tail = c;
	}
}

void sort(void)
{
	int a = 0;
	for (int i = 0; i < length() - 1; i++)
	{
		struct node *p = head;
		struct node *q = NULL;
		for (int j = 0; j < length() - 1 - i; j++)
		{
			q = p->next;
			if (q != NULL)
			{
				if (p->data > q->data)
				{
					a = p->data;
					p->data = q->data;
					q->data = a;
				}
				p = p->next;
			}
		}
	}
}
int main(int argc, const char *grav[])
{
	struct node *a = init_node(3);
	add_head(a);
	struct node *b = init_node(1);
	add_head(b);
	struct node *c = init_node(10);
	add_head(c);
	sort();
	print_list();
	return 0;
}
