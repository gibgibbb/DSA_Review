#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
	int elem;
	struct node *left, *right;
}*nodePtr;

void init(nodePtr *N){
	*N = NULL;
}

int main(){
	
	nodePtr A;
	init(&A);
	
	return 0;
}
