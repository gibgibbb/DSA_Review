#include <stdio.h>
#include <stdlib.h>
#define MAX 99

typedef struct {
	char FN[24], LN[16], MI;
}nameType;

typedef struct {
	unsigned int ID;
	nameType name;
	char course[8];
	int yrLevel;
}studRec;

typedef struct {
	studRec stud;
	int link;
}nodeType;

typedef struct {
	nodeType VSpace[MAX];
	int firstAvail;
}VHeap;

typedef struct {
	int front, rear, cnt;
	VHeap *ptr;
}queue;

void initQueue(queue *Q);
void insertFirst(queue *Q, studRec val);
void insertLast(queue *Q, studRec val);
void deleteFirst(queue *Q);
void deleteFirst(queue *Q);

void initQueue(queue *Q){
	Q->front = -1;
	Q->rear = -1;
	Q->cnt = 0;
	Q->ptr = malloc(sizeof(VHeap));
	if(Q->ptr != NULL){
		Q->ptr->firstAvail = -1;
	}
}

int main(){
	
	queue A;
	
	initQueue(&A);
	
	return 0;
}
