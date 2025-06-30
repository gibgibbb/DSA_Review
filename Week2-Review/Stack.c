#include <stdio.h>
#define MAX 10

typedef struct {
	char elem[MAX];
	int top;
}Stack;

void initStack(Stack *S);

void initStack(Stack *S){
	S->top = -1;
}

int main(){
	
	Stack A;
	
	initStack(&A);
	
	return 0;
}
