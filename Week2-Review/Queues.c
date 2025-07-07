#include <stdio.h>
#define MAX 8

// Queues 30/06/25 Circular Array

typedef struct {
	char elem[MAX];
	int front, rear;
}Queue;

void initQueue(Queue *Q);
void enqueue(Queue *Q, char x);
void dequeue(Queue *Q);
void display(Queue Q);
void insertSorted(Queue *Q, char x);

void insertSorted(Queue *Q, char val){
	int temp;
	if((Q->rear + 2) % MAX != Q->front){
		temp = (Q->rear + 1) % MAX;
	}
	for(; Q->front != temp && val > Q->elem[Q->front];){
		Q->rear = (Q->rear + 1) % MAX;
		Q->elem[Q->rear] = Q->elem[Q->front];
		Q->front = (Q->front + 1) % MAX;
	}
	Q->rear = (Q->rear + 1) % MAX ;
	Q->elem[Q->rear] = val;
	
	for(; Q->front != temp;){
		Q->rear = (Q->rear + 1) % MAX;
		Q->elem[Q->rear] = Q->elem[Q->front];
		Q->front = (Q->front + 1) % MAX;
	}
}

//void insertSorted(Queue *Q, char val){
//	int temp;
//	if((Q->rear + 2) % MAX != Q->front){
//		temp = (Q->rear + 1) % MAX;
//	}
//	
//	while(Q->front != temp && val > Q->elem[Q->front]){
//		Q->rear = (Q->rear + 1) % MAX;
//		Q->elem[Q->rear] = Q->elem[Q->front];
//		Q->front = (Q->front + 1) % MAX;
//	}
//	Q->rear = (Q->rear + 1) % MAX;
//	Q->elem[Q->rear] = val;
//	
//	while(Q->front != temp){
//		Q->rear = (Q->rear + 1) % MAX;
//		Q->elem[Q->rear] = Q->elem[Q->front];
//		Q->front = (Q->front + 1) % MAX;
//	}
//}

void display(Queue Q){
	int x;
	for(x = (Q.rear + 1) % MAX; x != Q.front; dequeue(&Q)){
		enqueue(&Q, Q.elem[Q.front]);
		printf("%c ", Q.elem[Q.front]);
	}
}

void enqueue(Queue *Q, char x){
	if((Q->rear + 2) % MAX != Q->front){
		Q->rear = (Q->rear + 1) % MAX;
		Q->elem[Q->rear] = x;
	}
}

void dequeue(Queue *Q){
	if((Q->rear + 1) % MAX != Q->front){
		Q->front = (Q->front + 1) % MAX;
	}
}

void initQueue(Queue *Q){
	Q->front = 0;
	Q->rear = MAX - 1;
}

int main (){
	
	Queue A;
	
	initQueue(&A);
//	enqueue(&A, 'a');
//	enqueue(&A, 'b');
//	enqueue(&A, 'c');
	insertSorted(&A, 'a');
	insertSorted(&A, 'b');
	insertSorted(&A, 'c');
	display(A);
	printf("\n");
	dequeue(&A);
	display(A);
	
	return 0;
}
