#include <stdio.h>
#define MAX 10

typedef struct {
	int elem[MAX];
	int lastNdx;
}PQ;

void init(PQ *pq){
	pq->lastNdx = -1;
}

int main(){
	
	
	PQ A;
	init(&A);

	return 0;
}
