#include <stdio.h>
#define MAX 10

typedef struct {
	int elem[MAX];
	int lastNdx;
}PQ;

void init(PQ *pq);
void insertToPOT(PQ *pq, int val);
int deleteMax(PQ *pq);
void display(PQ pq);
void heapsort(PQ *pq);

void heapsort(PQ *pq){
	int origNdx = pq->lastNdx;
	while(pq->lastNdx > 0){
		pq->elem[pq->lastNdx] = deleteMax(pq);
	}
	pq->lastNdx = origNdx;
}

void display(PQ pq){
	int x;
	for(x = 0; x <= pq.lastNdx; x++){
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

//MAXHEAP delete the MAX which is the root and return it to the calling function
int deleteMax(PQ *pq){
	int root = pq->elem[0];
	if(pq->lastNdx != -1){
		int x, lc, rc, min;
		pq->elem[0] = pq->elem[pq->lastNdx];
		for(x = 0, lc = 0; lc < pq->lastNdx; x = min){
			lc = (x * 2) + 1;
			rc = (x * 2) + 2;
			
			if(lc < pq->lastNdx){
				//min will check what is larger between lc and rc and will get rc if rc is larger and x if not
				min = (pq->elem[lc] > pq->elem[x])? lc : x;
				if(rc <= pq->lastNdx && pq->elem[rc] > pq->elem[min]){
					min = rc;
				}
	  			if(min != x){
					int temp = pq->elem[min];
					pq->elem[min] = pq->elem[x];
					pq->elem[x] = temp;
				} else {
					min = pq->lastNdx;
				}
			}
		}
		// To insert the value at the end
   		/* pq->elem[pq->lastNdx] = root; */
   		//If you want this display how the array looks like after deletion
   		pq->lastNdx--;
	}
	return root;
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
	insertToPOT(&A, 9);
	insertToPOT(&A, 4);
	display(A);
	printf("\n%d", A.lastNdx);
	
//	int catcher = deleteMax(&A);
//	printf("\ndeleted value is %d\n", catcher);
//	display(A);
	heapsort(&A);
	printf("\nHeapSort\n");
	display(A);

	return 0;
}
