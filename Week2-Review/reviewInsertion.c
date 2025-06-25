#include <stdio.h>
#define MAX 10

//review for array list insertion

typedef struct {
	char elem[MAX];
	int count;
}LIST;

void init(LIST *L);
void insertFirst(LIST *L, char val);
void display(LIST L);
void insertAt(LIST *L, char val, int pos);
void insertSorted(LIST *L, char val);

void insertSorted(LIST *L, char val){
	if(L->count < MAX){
		int x;
		for(x = L->count; x > 0 && L->elem[x] > val; x--){
			L->elem[x + 1] = L->elem[x];
		}
		L->elem[x] = val;
		L->count++;
	}
}

void insertAt(LIST *L, char val, int pos){
	int x;
	if(L->count < MAX){
		if(pos < L->count){
			for(x = L->count; x > pos; x--){
				L->elem[x] = L->elem[x - 1];
			}
			L->elem[pos] = val;
			L->count++;
		}
	}
}

void display(LIST L){
	int x;
	for(x = 0; x < L.count; x++){
		printf("%c ", L.elem[x]);
	}
}

void insertFirst(LIST *L, char val){
	int x;
	if(L->count < MAX){
		for(x = L->count; x > 0; x--){
			L->elem[x] = L->elem[x - 1];
		}
		L->elem[0] = val;
		L->count++;
	}
}

void init(LIST *L){
	L->count = 0;
}

int main(){
	
	LIST A;
	
	init(&A);
	insertSorted(&A, 'c');
	insertSorted(&A, 's');
	insertSorted(&A, 'u');
//	insertAt(&A, 'd', 0);
	display(A);
	
	return 0;
}
