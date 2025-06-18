#include <stdio.h>
#include <stdbool.h>
#define MAX 10

//18/06/2025 review
// list

typedef struct {
	char elem[MAX];
	int elemCount;
}LIST;

void init(LIST *L);
void insertFirst(LIST *L, char x);
void insertRear(LIST *L, char x);
bool find(LIST L, char x);
void display(LIST L);

void init(LIST *L){
	L->elemCount = 0;
}

void insertFirst(LIST *L, char x){
	int i;
	if(L->elemCount < MAX){
		for(i = L->elemCount++; i > 0; i--){
			L->elem[i] = L->elem[i - 1];
		}
		L->elem[0] = x;
	}
}

void insertRear(LIST *L, char x){
	if(L->elemCount < MAX){
		L->elem[L->elemCount++] = x;
	}
}

bool find(LIST L, char x){
	int i;
	for(i = 0; i < L.elemCount && L.elem[i] != x; i++){}
	return (i < L.elemCount)? true : false;
}

void display(LIST L){
	int i;
	for(i = 0; i < L.elemCount; i++){
		printf("%c ", L.elem[i]);
	}
}


int main(){
	
	LIST L;
	
	init(&L);
//	insertFirst(&L, 'U');
//	insertFirst(&L, 'S');
//	insertFirst(&L, 'C');
	insertRear(&L, 'U');
	insertRear(&L, 'S');
	insertRear(&L, 'C');
	display(L);
	
	bool retVal = find(L, 'S');
	printf("\n%d", retVal);
	
	return 0;
}
