#include <stdio.h>
#include <stdlib.h>

#define size 10

struct Node
{
	int data;
	struct Node *next;
};

struct Node *array[size];

void initHashTable()
{
	for (int i = 0; i < size; i++)
		array[i] = NULL;
}

struct Node *initNode(int data)
{
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	return node;
}

int hashCode(int data)
{
	return data % size;
}

void insertNode(int data)
{
	int index = hashCode(data);
	struct Node *node = initNode(data);
	if (array[index] == NULL)
	{
		array[index] = node;
	}
	else
	{
		struct Node *run = array[index];
		while (run->next != NULL)
		{
			run = run->next;
		}
		run->next = node;
	}
}

int searchNode(int data)
{
	int index = hashCode(data);
	struct Node *run = array[index];
	while (run != NULL)
	{
		if (run->data == data)
		{
			return 1;
		}
		run = run->next;
	}
	return 0;
}

int deleteNode(int data)
{
	int index = hashCode(data);
	struct Node *run = array[index];
	struct Node *prev;
	if (run != NULL)
	{
		if (run->data == data)
		{
			array[index] = run->next;
			free(run);
			return 1;
		}
		else
		{
			while (run->next != NULL)
			{
				prev = run;
				run = run->next;
				if (run->data == data)
				{
					prev->next = run->next;
					free(run);
					return 1;
				}
			}
		}
	}
	return 0;
}

void printHashTable()
{
	for (int index = 0; index < size; index++)
	{
		printf("Index : [%d] --->", index);
		struct Node *run = array[index];
		while (run != NULL)
		{
			printf("%d --->", run->data);
			run = run->next;
		}
		printf("NULL\n");
	}
}

int main(int argc, const char *argv[])
{
	initHashTable();
	insertNode(0);
	insertNode(10);
	insertNode(20);
	insertNode(30);
	insertNode(40);
	insertNode(1);
	insertNode(11);
	insertNode(2);
	insertNode(12);
	insertNode(3);
	insertNode(13);
	insertNode(4);
	insertNode(14);
	insertNode(5);
	insertNode(15);
	insertNode(6);
	insertNode(16);
	insertNode(7);
	insertNode(17);
	insertNode(8);
	insertNode(18);
	insertNode(9);
	insertNode(19);
	printHashTable();
	printf("%d \n", searchNode(40));
	printf("%d \n", deleteNode(40));
	printHashTable();
	return 0;
}
