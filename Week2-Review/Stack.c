#include <stdio.h>
#define MAX 10

typedef struct {
	char elem[MAX];
	int top;
}Stack;

void initStack(Stack *S);
void push(Stack *S, char val);
char top(Stack S);
void pop(Stack *S);
void display(Stack S);

char top(Stack S){
	return (S.top != -1)? S.elem[S.top]: '\0';
}

void display(Stack S){
	Stack temp;
	initStack(&temp);
	
	for(; S.top != -1; pop(&S)){
		char c = S.elem[S.top];
		push(&temp, c);
		printf("%c ", c);
	}
}

void push (Stack *S, char val){
	if(S->top != MAX - 1){
		S->elem[++S->top] = val;
	}
}

void pop(Stack *S){
	if(S->top != -1){
		S->top--;
	}
}


void initStack(Stack *S){
	S->top = -1;
}

int main(){
	
	Stack A;
	initStack(&A);
	push(&A, 'a');
	push(&A, 'b');
	push(&A, 'c');
	display(A);
	return 0;
}
