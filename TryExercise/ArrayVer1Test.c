#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
	char elem[MAX];
	int avail; //should be count
}LIST;

void init(LIST *L);
void insertLast(LIST *L, char val);
void deleteFirstOccurance(LIST *L, char val);
void deleteAllOccurance(LIST *L, char val);
void display(LIST L);

void init(LIST *L){
	L->avail = -1;
}

void insertLast(LIST *L, char val){
	if(L->avail != MAX){
		L->elem[++L->avail] = val;
	}
}

void deleteAllOccurance(LIST *L, char val){
	int x;
	for(x = 0; x <= L->avail;){
		if(L->elem[x] == val){
			int y;
			for(y = x; y < L->avail; y++){
				L->elem[y] = L->elem[y + 1];
			}
			L->avail--;
		} else {
			x++;
		}
	}
}

void deleteFirstOccurance(LIST *L, char val){
	int x;
	for(x = 0; x < L->avail && L->elem[x] != val; x++){}
	for(; x < L->avail; x++){
		L->elem[x] = L->elem[x + 1];
	}
	L->avail--;
}

void display(LIST L){
	int x;
	for(x = 0; x <= L.avail; x++){
		printf("%c ", L.elem[x]);
	}
}

int main (){
	
	LIST A;
	
	init(&A);
	
	insertLast(&A, 'd');
	insertLast(&A, 'b');
	insertLast(&A, 'c');
	insertLast(&A, 'a');
	display(A);
	
	printf("\n");
	
	deleteFirstOccurance(&A, 'a');
	display(A);
	
	return 0;
}
