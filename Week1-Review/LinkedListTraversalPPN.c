#include <stdio.h>
#include <stdlib.h>

//23/06/25 Linked List Traversal Using Pointer-to-Pointer To a Node (PPN)

// Exercise
//typedef struct {
//	char LName[16];
//	char FName[24];
//	char MI;
//}Name;
//
//typedef struct {
//	Name studName;
//	unsigned int ID;
//	char Course[32];
//	int Year;
//}Record;
//
//typedef struct node {
//	Record studRec;
//	struct node *link;
//}Node, *LIST;

typedef struct node{
	char elem;
	struct node *link;
}Node, *LIST;

void init(LIST *L);
void appendEnd(LIST *L, char val);
void display(LIST L);

void display(LIST L){
	LIST trav;
	for(trav = L; trav != NULL; trav = trav->link){
		printf("%c ", trav->elem);
	}
}

void appendEnd(LIST *L, char val){
	LIST *trav, temp;
	for(trav = L; *trav != NULL; trav = &(*trav)->link){}
	temp = malloc(sizeof(struct node));
	if(temp != NULL){
		temp->elem = val;
		temp->link = *trav;
		*trav = temp;
	}	
}

void init(LIST *L){
	*L = NULL;
}

int main(){
	
	LIST L;
	init(&L);
	appendEnd(&L, 'u');
	display(L);
	
	return 0;
}
