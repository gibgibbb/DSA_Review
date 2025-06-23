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
void appendEnd(LIST *L, char )

void init(LIST *L){
	*L = NULL;
}

int main(){
	
	LIST L;
	init(&L);
	
	return 0;
}
