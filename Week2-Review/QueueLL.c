#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 5

typedef struct node{
	char elem;
	struct node* link;
}*LIST;

typedef struct {
	LIST front, rear;
}Queue;

void initQ(Queue *Q);
void enqueue(Queue *Q, char val);
void dequeue(Queue *Q);
void display(Queue Q);
void insertSorted(Queue *Q, char val);

void initQ(Queue *Q){
	Q->front = Q->rear = NULL;
}

void enqueue(Queue *Q, char val){
	LIST temp = malloc(sizeof(struct node));
	if(temp != NULL){
		temp->link = NULL;
		temp->elem = val;
		if(Q->front != NULL){
			Q->rear->link = temp;
		}else {
			Q->front = temp;
		}
		Q->rear = temp;
	}
}

void dequeue(Queue *Q){
	if(Q->front != NULL){
		LIST temp = Q->front;
		Q->front = temp->link;
		if(temp == Q->rear){
			Q->rear = NULL;
		}
	}
}

void insertSorted(Queue *Q, char val){
	LIST temp;
	Queue C;
	C.front = C.rear = NULL;
	
	for(;Q->front != NULL && val > Q->front->elem;){
		temp = Q->front;
		Q->front = temp->link;
		if(C.front != NULL){
			C.rear->link = temp;
		} else {
			C.front = temp;
		}
		C.rear = temp;
	}
	temp = malloc(sizeof(struct node));
	if(temp != NULL){
		temp->elem = val;
		temp->link = NULL;
		if(C.front != NULL){
			C.rear->link = temp;
		} else {
			C.front = temp;
		}
		C.rear = temp;
	}
	
	for(;Q->front != NULL;){
		temp = Q->front;
		Q->front = temp->link;
		temp->link = NULL;
		C.rear->link = temp;
		C.rear = temp;
	}
	
	for(;C.front != NULL;){
		temp = C.front;
		C.front = temp->link;
		temp->link = NULL;
		if(Q->front != NULL){
			Q->rear->link = temp;
		} else {
			Q->front = temp;
		}
		Q->rear = temp;
	}
}

void display(Queue Q){

}

int main(){
	
	Queue A;
	initQ(&A);
	
//	enqueue(&A, 'a');
//	enqueue(&A, 'b');
//	enqueue(&A, 'c');
	insertSorted(&A, 'h');
	insertSorted(&A, 'f');
	insertSorted(&A, 'd');
//	dequeue(&A);
//	display(A);
	
	return 0;
}
