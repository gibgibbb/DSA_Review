#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 5

typedef struct {
	char elem;
	int link;
}Nodetype;

typedef struct {
	Nodetype Nodes[MAX];
	int avail;
}VirtualHeap;

typedef struct {
	int front, rear;
}QueueCB;

void initQueue(QueueCB *Q);
void initVH(VirtualHeap *VH);
void enqueue(QueueCB *Q, VirtualHeap *VH, char val);
void dequeue(QueueCB *Q, VirtualHeap *VH);
void insertSorted(QueueCB *Q, VirtualHeap *VH, char val);

void insertSorted(QueueCB *Q, VirtualHeap *VH, char val){
	int temp;
	QueueCB C;
	C.front = C.rear = -1;
	
	for(;Q->front != -1 && val > VH->Nodes[Q->front].elem;){
		temp = Q->front;
		Q->front = VH->Nodes[temp].link;
		if(C.front != -1){
			VH->Nodes[C.rear].link = temp;
		} else {
			C.front = temp;
		}
		C.rear = temp;
	}
	
	temp = VH->avail;
	if(temp != -1){
		VH->avail = VH->Nodes[temp].link;
		VH->Nodes[temp].elem = val;
		VH->Nodes[temp].link = -1;
		if(C.front != -1){
			VH->Nodes[C.rear].link = temp;
		} else {
			C.front = temp;
		}
		C.rear = temp;
	}
	
	for(;Q->front != -1;){
		temp = Q->front;
		Q->front = VH->Nodes[temp].link;
		VH->Nodes[temp].link = -1;
		VH->Nodes[C.rear].link = temp;
		C.rear = temp;
	}
	
	for(;C.front != -1;){
		temp = Q->front;
		Q->front = VH->Nodes[temp].link;
		if(Q->front != -1){
			VH->Nodes[Q->rear].link = temp;
		} else {
			Q->front = temp;
		}
		Q->rear = temp;
	}
}

void initQueue(QueueCB *Q){
	Q->front = Q->rear = -1;
}

void initVH(VirtualHeap *VH){
	VH->avail = MAX - 1;
	int x;
	for(x = VH->avail; x >= 0; x--){
		VH->Nodes[x].link = x - 1;
	}
}

void enqueue(QueueCB *Q, VirtualHeap *VH, char val){
	int temp;
	temp = VH->avail;
	if(temp != -1){
		VH->avail = VH->Nodes[temp].link;
		VH->Nodes[temp].elem = val;
		VH->Nodes[temp].link = -1;
		if(Q->front != -1){
			VH->Nodes[Q->rear].link = temp;
		} else {
			Q->front = temp;
		}
		Q->rear = temp;
	}
}

void dequeue(QueueCB *Q, VirtualHeap *VH){
	if(Q->front != -1){
		int temp = Q->front;
		Q->front = VH->Nodes[temp].link;
		if(temp == Q->rear){
			Q->rear = -1;
		}
		VH->Nodes[temp].link = VH->avail;
		VH->avail = temp;
	}
}

int main(){
	
	QueueCB A;
	VirtualHeap B;
	initVH(&B);
	initQueue(&A);
	
	enqueue(&A, &B, 'a');
	enqueue(&A, &B, 'a');
	enqueue(&A, &B, 'a');
	
	return 0;
}
