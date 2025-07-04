#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
	char FN[24], LN[16], MI;
}Nametype;

typedef struct {
	Nametype data[MAX];
	int avail; //should be count
}LIST;

void init(LIST *L);
void insertLast(LIST *L, Nametype val);
void deleteFirstOccurence(LIST *L, char val[]);
void deleteAllOccurence(LIST *L, char val[]);
void display(LIST L);

void init(LIST *L){
	L->avail = -1;
}

void insertLast(LIST *L, Nametype val){
	if(L->avail != MAX){
		L->data[++L->avail] = val;
	}
}

void deleteAllOccurence(LIST *L, char val[]){
//	int x;
//	for(x = 0; x <= L->avail;){
//		if(L->data[x] == val){
//			int y;
//			for(y = x; y < L->avail; y++){
//				L->data[y] = L->elem[y + 1];
//			}
//			L->avail--;
//		} else {
//			x++;
//		}
//	}
}

void deleteFirstOccurence(LIST *L, char val[]){
	int x;
	for(x = 0; x < L->avail && strcmp(L->data[x].FN, val) != 0; x++){}
	for(; x < L->avail; x++){
		L->data[x] = L->data[x + 1];
	}
	L->avail--;
}

void display(LIST L){
	int x;
	for(x = 0; x <= L.avail; x++){
		printf("%s ", L.data[x].FN);
	}
}

int main (){
	
	LIST A;
	
	init(&A);
	
	Nametype studA = {"Lemuel", "Diaz", 'W'};
	Nametype studB = {"Lawrence", "Nyeta", 'C'};
	Nametype studC = {"Kristian", "Waker", 'D'};
	Nametype studD = {"Blaire", "Caldevilla", 'S'};
	
	insertLast(&A, studA);
	insertLast(&A, studB);
	insertLast(&A, studC);
	insertLast(&A, studD);
	display(A);
	
	printf("\n");
	
	deleteFirstOccurence(&A, "Kristian");
	display(A);
	
	return 0;
}
