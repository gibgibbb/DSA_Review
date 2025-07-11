#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int elem;
	struct node *link;
}ctype, *SET;

void initSet(SET *S);
void insert(SET *S, int val);
void display(SET A);
SET Union(SET A, SET B);

SET Union(SET A, SET B){
	SET C, aptr, bptr, *cptr;
	C = NULL;
	aptr = A;
	bptr = B;
	cptr = &C;
	for(; aptr != NULL && bptr != NULL; ){
		*cptr = (SET)malloc(sizeof(struct node));
		if(aptr->elem < bptr->elem){
			(*cptr)->elem = aptr->elem;
			aptr = aptr->link;
		} else {
			if(aptr->elem == bptr->elem){
				aptr = aptr->link;
			}
			(*cptr)->elem = bptr->elem;
			bptr = bptr->link;
		}
		cptr = &(*cptr)->link;
	}
	if(bptr != NULL){
		aptr = bptr;
	}
	for(;aptr != NULL;){
		(*cptr)->elem = aptr->elem;
		aptr = aptr->link;
		cptr = &(*cptr)->link;
	}
	*cptr = NULL;
	return C;
}

SET Intersection(SET A, SET B){
	
}

void initSet(SET *S){
	*S = NULL;
}

void display(SET A){
	SET temp = malloc(sizeof(struct node));
	if(temp != NULL){
		SET trav;
		for(trav = A; trav != NULL; trav = trav->link){
			printf("%d ", trav->elem);
		}
	}
}

//sorted and unique
void insert(SET *S, int val){
	SET *trav, temp;
	for(trav = S; *trav != NULL && (*trav)->elem < val; trav = &(*trav)->link){}
	if(*trav == NULL || (*trav)->elem != val){
		temp = (SET)malloc(sizeof(struct node));
		if(temp != NULL){
			temp->elem = val;
			temp->link = *trav;
			*trav = temp;
		}
	}
}

int main(){
	
	SET A, B;
	initSet(&A);
	initSet(&B);
	
	int insertA[4] = {1, 3, 5, 7};
	int insertB[4] = {1, 4, 5, 7};
	
	int x, y;
	for(x = 0; x < 4; x++){
		insert(&A, insertA[x]);
	}
	
 	for(x = 0; y < 4; y++){
		insert(&B, insertB[y]);
	}
	
	SET C = Union(A, B);
	
//	display(A);
	
	return 0;
}
