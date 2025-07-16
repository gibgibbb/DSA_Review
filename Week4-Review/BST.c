#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
	int elem;
	struct node *left, *right;
}*nodePtr;

void init(nodePtr *N);
void insert(nodePtr *N, int val);
void delete(nodePtr *N, int val);
void display(nodePtr N);

void display(nodePtr N){
	if(N != NULL){
		printf("%d ", N->elem);
		display(N->left);
		display(N->right);
	}
}

void insert(nodePtr *N, int val){
	nodePtr *trav, temp;
	for(trav = N; *trav != NULL && (*trav)->elem != val;){
		trav = (val < (*trav)->elem) ? &(*trav)->left : &(*trav)->right;
	}
	if(*trav == NULL){
		temp = malloc(sizeof(struct node));
		temp->elem = val;
		temp->left = temp->right = NULL;
		*trav = temp;
	}
}

void delete(nodePtr *N, int val){
	nodePtr *trav, temp;
	for(trav = N; *trav != NULL && (*trav)->elem != val;){
		trav = (val < (*trav)->elem) ? &(*trav)->left : &(*trav)->right;
	}
	if(*trav != NULL){
		temp = *trav;
		if(temp->left != NULL && temp->right != NULL){
			nodePtr *trav2;
			for(trav2 = &temp->left; *trav != NULL && (*trav2)->right != NULL; trav2 = &(*trav2)->right){}
			temp->elem = (*trav2)->elem;
			temp = *trav2;
			*trav2 = temp->left;
		} else {
			*trav = (temp->left != NULL) ? temp->left : temp->right;
		}
		free(temp);
	}
}

void init(nodePtr *N){
	*N = NULL;
}

int main(){
	
	nodePtr A;
	init(&A);
	insert(&A, 5);
	insert(&A, 10);
	insert(&A, 3);
	display(A);
	delete(&A, 10);
	printf("\ndelete\n");
	display(A);
	
	return 0;
}
