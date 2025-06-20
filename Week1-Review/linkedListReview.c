#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//06/19/25 Introduction to Linked List 

typedef struct node {
	char elem;
	struct node *next;
}Node, *LIST;

void init(LIST *L);
void insertFirst(LIST *L, char x);
void display(LIST L);

void insertFirst(LIST *L, char x){

	LIST newNode = malloc(sizeof(struct node));
	if(newNode!= NULL){
		newNode->elem = x;
		newNode->next = *L;
		*L = newNode;
	}
}

void display(LIST L){
	LIST trav;
	for(trav = L; trav != NULL; trav = trav->next){
		printf("%c ", trav->elem);
	}
}

void init(LIST *L){
	*L = NULL;
}

int main(){
	
	LIST L;
	
	init(&L);
	insertFirst(&L, 'u');
	insertFirst(&L, 's');
	insertFirst(&L, 'c');
	display(L);
	
	return 0;
	
}
