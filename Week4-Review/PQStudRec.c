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

void insertToPOT(PQ *pq, studRec val){
	
}

void init(PQ *pq){
	pq->lastIndex = -1;
}

int main(){
	
	PQ A;
	init(&A);
	
	return 0;
}
