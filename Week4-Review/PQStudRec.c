#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

// Student Record Structure
typedef struct {
    char FName[24], LName[16], MI;
} nametype;

typedef struct {
    unsigned int ID;
    nametype SName;
    char course[8];
    int yr;
    int priority;  // Added priority field
} studRec;

// Priority Queue using Array Implementation
typedef struct {
    studRec heap[MAX];
    int lastIndex;  // Index of last element (-1 if empty)
} PQ;

void init(PQ *pq);
void insertToPOT(PQ *pq, studRec val);
void displayPOT(PQ pq);
void heapSort(PQ *pq);
void displayHeapSort(PQ pq);
studRec deleteMax(PQ *pq);

void displayHeapSort(PQ pq){
	int x;
	for(x = 0; x <= pq.lastIndex; x++){
		printf("\nIndex %d:", x);
        printf("\nID: %u", pq.heap[x].ID);
        printf("\nName: %s %s %c",
               pq.heap[x].SName.FName,
               pq.heap[x].SName.LName,
               pq.heap[x].SName.MI);
        printf("\nPriority: %d", pq.heap[x].priority);
        printf("\n-----------------");
	}
}

void heapSort(PQ *pq){
	int origNdx = pq->lastIndex;
	while(pq->lastIndex > 0){
		pq->heap[pq->lastIndex] = deleteMax(pq);
	}
	pq->lastIndex = origNdx;
}

studRec deleteMax(PQ *pq){
	studRec root = pq->heap[0];
	if(pq->lastIndex != -1){
		int x, lc, rc, min;
		pq->heap[0] = pq->heap[pq->lastIndex];
		for(x = 0, lc = 0; lc < pq->lastIndex; x = min){
			lc = (x * 2) + 1;
			rc = (x * 2) + 2;
			if(lc < pq->lastIndex){
				min = (pq->heap[lc].priority > pq->heap[x].priority) ? lc : x;
				if(rc <= pq->lastIndex && pq->heap[rc].priority > pq->heap[min].priority){
					min = rc;
				}
				if(min != x){
					studRec temp = pq->heap[min];
					pq->heap[min] = pq->heap[x];
					pq->heap[x] = temp;
				} else {
					min = pq->lastIndex;
				}
			}
		}
		pq->lastIndex--;
	}
	return root;
}

void displayPOT(PQ pq){
	int i;
	for(i = 0; i <= pq.lastIndex; i++){
		printf("\nIndex %d:", i);
        printf("\nID: %u", pq.heap[i].ID);
        printf("\nName: %s %s %c",
               pq.heap[i].SName.FName,
               pq.heap[i].SName.LName,
               pq.heap[i].SName.MI);
        printf("\nPriority: %d", pq.heap[i].priority);
        printf("\n-----------------");
	}
}

//MAXHeap
void insertToPOT(PQ *pq, studRec val){
	if(pq->lastIndex < MAX - 1){
		pq->lastIndex++;
		int x, parent;
		for(x = pq->lastIndex, parent = (x - 1)/2; x > 0 && val.priority > pq->heap[parent].priority; x = parent, parent = (parent - 1)/2){
			pq->heap[x] = pq->heap[parent];
		}
		pq->heap[x] = val;
	}
}

void init(PQ *pq){
	pq->lastIndex = -1;
}

int main(){
	
	PQ pq;
	studRec A = {1001, {"John", "Doe", 'A'}, "BSCS", 1, 3};
	studRec B = {1002, {"Jane", "Smith", 'B'}, "BSIT", 2, 1};
	studRec C = {1003, {"Bob", "Johnson", 'C'}, "BSCS", 1, 3};
    studRec D = {1004, {"Alice", "Brown", 'D'}, "BSIT", 3, 2};
    studRec E = {1005, {"Charlie", "Wilson", 'E'}, "BSCS", 2, 1};
	init(&pq);
	
	insertToPOT(&pq, A);
	insertToPOT(&pq, B);
	insertToPOT(&pq, C);
	insertToPOT(&pq, D);
	insertToPOT(&pq, E);
	printf("This is what the POT looks like");
	displayPOT(pq);
	
	printf("\nThis is the sorted studRec\n");
	
	heapSort(&pq);
	displayHeapSort(pq);
	
	return 0;
}
