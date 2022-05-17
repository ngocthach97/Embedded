#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node {
	int data;
	struct node *next;
	struct node *prev;
};

struct node * head = NULL;

struct node *tail = NULL;

struct node * init_node(int data){
	struct node * n = (struct node *)malloc(sizeof(struct node));
	n->data = data;
	n->next = NULL;
	n->prev = NULL;
	return n;
}

void add_head(struct node * n){
	if(head == NULL){
		head = n;
		tail = n;
	}
	else {
		n->next = head ;
		head->prev = n;
		head = n;
	}
}

void print_list (void){
	struct node *p = head;
	if(p == NULL){
		return;
	}
	else{
		while(1){
			printf("data node = %d \n",p->data);
			if(p->next == NULL){
				return;
			}
			p = p->next;
		}
	}
}

void add_tail(struct node *n){
	if(head == NULL){
		head = n;
		tail = n;
	}
	else{
		n->prev = tail;
		head->next = n;
		tail = n;
	}
}

void delete_head(void){
	if(head == NULL){
		return;
	}
	else{
		struct node *p = head;
		if(p->next != NULL){
			head = p->next;
			head->prev = NULL;
			p->next=NULL;
		}
		free(p);
	}
}

void delete_tail(void){
	if(tail == NULL){
		return;
	}
	else{
		struct node *p = tail;
		if(tail != head){
			tail = p->prev;
			tail->next = NULL;
			p->prev = NULL;
		}
		free(p);
	}
}

bool searchNode(int data){
	if(head != NULL){
		struct node *p = head;
		while(p != NULL){
			if(p->data == data){
				return true;
			}
			p = p->next;
		}
	}
	return false;
}
bool isEmpty(void){
	if(head == NULL && tail == NULL){
		return true;
	}
	return false;
}

int length(void){
	int length = 0;
	struct node *p = head;
	while(1){
		length ++;
		if(p->next == NULL){
			break;
		}
		p = p->next;
	}
	return length;
}

int main(int argc, const char *argv[] ){
	for(int i = 0 ; i < 10 ; i ++){
		struct node *a = init_node(i);
		add_head(a);
	}
	delete_head();
	print_list();
	printf("search node = %d \n", searchNode(5));
	printf("length list = %d \n",length());
	return 0;
}
