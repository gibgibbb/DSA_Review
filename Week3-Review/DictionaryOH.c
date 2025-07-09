#include <stdio.h>
#define MAX 10

typedef struct node {
	int elem;
	struct node *link;
}*SET;

typedef SET Dictionary[MAX];

void init(Dictionary D){
	int x;
	for(x = 0; x < MAX; x++){
		D[x] = NULL;
	}
}

int main(){
	
	Dictionary A;
	init(A);
	
	return 0;
}
