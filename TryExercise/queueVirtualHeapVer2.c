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

queue initQueue(VHeap *VH);
void initVHeap(VHeap *VH);
void insertFirst(queue *Q, studRec val);
void insertLast(queue *Q, studRec val);
void deleteFirst(queue *Q);
void deleteFirst(queue *Q);

queue initQueue(VHeap *VH){
	queue Q;
	
	Q.cnt = 0;
	Q.front = Q.rear = -1;
	Q.ptr = VH;
	
	return Q;
}

void initVHeap(VHeap *VH){
	VH->firstAvail = MAX - 1;
	int x;
	for(x = VH->firstAvail; x >= 0; x--){
		VH->VSpace[x].link = x - 1;
	}
}

int main(){
	
	queue A;
	VHeap V;
	initVHeap(&V);
	A = initQueue(&V);
	
	return 0;
}
