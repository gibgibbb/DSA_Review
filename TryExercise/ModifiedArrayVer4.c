#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10

typedef struct node {
	char FN[24], LN[16], MI;
}Nametype;

typedef struct LIST{
	Nametype *name;
	int count;	
}*LISTPtr;

void init(LISTPtr *L);
void insertFirst(LISTPtr *L, Nametype val);
void deleteFirst(LISTPtr *L);
bool findElem(LISTPtr L, char val);

void display(LISTPtr L);

void display(LISTPtr L){
	int x;
	for(x = L->count; x >= 0; x--){
		printf("%s ", L->name[x].FN);
	}
}

void init(LISTPtr *L){
	*L = (LISTPtr)malloc(sizeof(struct LIST));
	if(*L != NULL){
		(*L)->name = malloc(MAX * sizeof(struct node));
		(*L)->count = -1;
	}
}

void insertFirst(LISTPtr *L, Nametype val){
	if((*L)->count < MAX){
		int x;
		for(x = (*L)->count + 1; x > 0; x--){
			(*L)->name[x] = (*L)->name[x - 1];
		}
		(*L)->name[0] = val;
		(*L)->count++;
	}
}

bool findElem(LISTPtr L, char val){
	int x;
	for(x = 0; x < L->count && L->name[x].MI != val; x--){}
	return(L->name[x].MI == val) ? true : false;
}

void deleteFirst(LISTPtr *L){
	if((*L)->count != -1){
		int x;
		for(x = 0; x < (*L)->count; x++){
			(*L)->name[x] = (*L)->name[x + 1];
		}
		(*L)->count--;
	}
}

int main(){
	
	LISTPtr A;
	init(&A);
	
	Nametype studA = {"Kristian", "Wohoy", 'D'};
	Nametype studB = {"Kent", "Dungalon", 'C'};
	Nametype studC = {"Allen", "Nicdao", 'S'};
	
	insertFirst(&A, studA);
//	insertFirst(&A, studB);
//	insertFirst(&A, studC);
	
	display(A);
	
	deleteFirst(&A);
	printf("\n");
	display(A);
	
	bool retVal = findElem(A, 'D');
	printf("\n%d", retVal);
		
	return 0;
}
