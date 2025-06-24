#include <stdio.h>
#include <stdlib.h>

//24/06/25 Linked List Traversal Using Pointer-to-Pointer To a Node (PPN) Week 2

typedef struct node{
	char elem;
	struct node *link;
}Node, *LIST;

void init(LIST *L);
void appendEnd(LIST *L, char val);
void display(LIST L);
void delVal(LIST *L, char val);
void delAllOccur(LIST *L, char val);

void delAllOccur(LIST *L, char val){
	LIST *trav, temp;
	for(trav = L; *trav != NULL;){
		if((*trav)->elem == val){
			temp = *trav;
			*trav = (*trav)->link;
			free(temp);
		} else {
			trav = &(*trav)->link;
		}
	}
}

void delVal(LIST *L, char val){
	LIST *trav, temp;
	for(trav = L; *trav != NULL && (*trav)->elem != val; trav = &(*trav)->link){}
	if(*trav != NULL){
		temp = *trav;
		*trav = (*trav)->link;
		free(temp);
	}
}

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
	appendEnd(&L, 's');
	appendEnd(&L, 'c');
	appendEnd(&L, 's');
	appendEnd(&L, 'd');
	appendEnd(&L, 'a');
	display(L);
	printf("\n");
	delAllOccur(&L, 's');
	display(L);
	
	return 0;
}
