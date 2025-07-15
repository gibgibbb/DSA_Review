#include <stdio.h>
#define MAX 10

typedef struct {
	int elem[MAX];
	int lastNdx;
}PQ;

void init(PQ *pq);
void insertToPOT(PQ *pq, int val);
void display(PQ pq);

void display(PQ pq){
	int x;
	for(x = 0; x < pq.lastNdx; x++){
		printf("%d ", pq.elem[x]);
	}
}

//MAXHEAP val > parentElem (parent should be larger than children)
void insertToPOT(PQ *pq, int val){
	if(pq->lastNdx < MAX - 1){
		pq->lastNdx++;
		int x, parentNdx;
		for(x = pq->lastNdx, parentNdx = (x - 1)/2; x > 0 && val > pq->elem[parentNdx]; x = parentNdx, parentNdx = (parentNdx - 1)/2){
			pq->elem[x] = pq->elem[parentNdx];
		}
		pq->elem[x] = val;
	}
}

void init(PQ *pq){
	pq->lastNdx = -1;
}

int main(){
	
	
	PQ A;
	init(&A);
	insertToPOT(&A, 5);
	insertToPOT(&A, 6);
	insertToPOT(&A, 15);
	insertToPOT(&A, 7);
	display(A);

	return 0;
}
