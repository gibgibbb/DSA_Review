#include <stdio.h>
#define MAX 8

// Queues 30/06/25

typedef struct {
	char elem[MAX];
	int front, rear;
}Queue;

void initQueue(Queue *Q);
void enqueue(Queue *Q, char x);
void dequeue(Queue *Q, char x);

void enqueue(Queue *Q, char x){
	if((Q->rear + 2) % MAX != Q->front){
		Q->rear = (Q->rear + 1) % MAX;
		Q->elem[Q->rear] = x;
	}
}

void initQueue(Queue *Q){
	Q->front = 0;
	Q->rear = MAX - 1;
}

int main (){
	
	Queue A;
	
	initQueue(&A);
	enqueue(&A, 'a');
	enqueue(&A, 'b');
	
	return 0;
}
