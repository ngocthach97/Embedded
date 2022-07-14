#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
}

struct node * root = NULL;

struct node * init_node(int data){
	struct node *n = (struct node*)malloc(sizeof(struct node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void add_tree (struct node *n){
	if(root == NULL){
		root = n;
	}
	else{
		struct node *p = root;
		struct node *q = NULL;
		while(1){
			q = p;
			if(p->data > data){
				p = p->left;
				if(p == NULL){
					q->left = n;
					return;
				}
			}
			else{
				p = p->right;
				if(p == NULL){
					q->right = n;
					return;
				}
			}
		}
	}
}

bool search_node(int data){
	if(root != NULL){
		struct node *p = root;
		while(1){
			if(p != NULL){
				if(p->data > data){
					p = p->left;
				}
				else if(p-> data < data){
					p = p->right;
				}
				else{
					return true;
				}
			}
			return false;
		}
	}
}
int main(int argc , const char *argv[]){
	printf("never give up !\n");
	return 0 ;
}
