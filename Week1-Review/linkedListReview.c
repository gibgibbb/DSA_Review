#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//06/19/25 Introduction to Linked List 

typedef struct node {
	int num;
	struct node *next;
}Node, *LIST;

void init(LIST *L);
void insertFirst(LIST *L, int x);
void display(LIST L);
bool isMem(LIST L, int x);
LIST getEven(LIST L);
bool delNum(LIST *L, int x);

bool delNum(LIST *L, int x){
	LIST *trav, temp;
	for(trav = L; *trav != NULL && (*trav)->num != x; trav = &(*trav)->next){}
	
	if(*trav != NULL){
		temp = *trav;
		*trav = (*trav)->next;
		free(temp);
	}
	return (*trav != NULL) ? true:false;
}

LIST getEven(LIST L){
	LIST retVal = NULL;
	LIST temp, trav;
	for(trav = L; trav != NULL; trav = trav->next){
		if(trav->num % 2 == 0){
			temp = malloc(sizeof(struct node));
			temp->num = trav->num;
			temp->next = retVal;
			retVal = temp;
		}
	}
	return retVal;
}

bool isMem(LIST L, int x){
	LIST trav;
	for(trav = L; trav != NULL && trav->num != x; trav = trav->next){}
	return (trav != NULL) ? true:false;
}

void insertFirst(LIST *L, int x){

	LIST newNode = malloc(sizeof(struct node));
	if(newNode!= NULL){
		newNode->num = x;
		newNode->next = *L;
		*L = newNode;
	}
}

void display(LIST L){
	LIST trav;
	for(trav = L; trav != NULL; trav = trav->next){
		printf("%d ", trav->num);
	}
}

void init(LIST *L){
	*L = NULL;
}

int main(){
	
	LIST L;
	
	init(&L);
	insertFirst(&L, 4);
	insertFirst(&L, 2);
	insertFirst(&L, 5);
	insertFirst(&L, 7);
	insertFirst(&L, 8);
	display(L);
	
	bool retVal = isMem(L, 2);
	printf("\n%d", retVal);
	
	LIST evenList = getEven(L);
	printf("\n");
	display(evenList);
	
	bool retVal2 = delNum(&L, 4);
	printf("\n%d\n", retVal2);
	display(L);
	
	return 0;
	
}
