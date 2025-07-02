#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct stack{
	char elem[MAX];
	int top;
}*Stack;

void initStack(Stack *S){
	*S = malloc(sizeof(struct stack));
	if(*S != NULL){
		(*S)->top = -1;
	}
}

void push(Stack *S, char val){
	if((*S)->top != MAX){
		(*S)->top++;
		(*S)->elem[(*S)->top] = val;
	}
}

void pop(Stack *S){
	if((*S)->top != -1){
		(*S)->top--;
	}
}

void display(Stack S){
	Stack temp;
	initStack(&temp);
	
	for(; S->top != -1; pop(&S)){
		push(&temp, S->elem[S->top]);
		printf("%c ", S->elem[S->top]);
	}
}

int main (){
	
	Stack A;
	
	initStack(&A);
	push(&A, 'a');
	push(&A, 'b');
	push(&A, 'c');
	
	display(A);
	
	return 0;
}
