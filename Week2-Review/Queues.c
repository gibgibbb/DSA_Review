#include <stdio.h>
#define MAX 8

// Queues 30/06/25

typedef struct {
	char elem[MAX];
	int front, rear;
}Queue;

void initQueue(Queue *Q);

void initQueue(Queue *Q){
	Q->front = 0;
	Q->rear = MAX - 1;
}

int main (){
	
	Queue A;
	
	initQueue(&A);
	
	return 0;
}
