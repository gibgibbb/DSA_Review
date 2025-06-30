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
void insertBottom(Stack *S, char val);

void insertBottom(Stack *S, char val){
	Stack temp;
	initStack(&temp);
	
	// Move everything from S to temp
	for(; S->top != -1; pop(S)){
		push(&temp, top(*S));
	}
	
	// Now we reached the end, insert the element
	push(S, val);
	
	// Move back temp to S
	for(; temp.top != -1; pop(&temp)){
		push(S, top(temp));
	}
	
	/*if while loop
	while(S->top != -1){
		push(&temp, top(*S));
		pop(S);
	}
	push(S, val);
	
	while(temp.top != -1){
		push(S, top(&temp));
		pop(&temp);
	}
	*/
}

char top(Stack S){
	return (S.top != -1)? S.elem[S.top]: '\0';
}

void display(Stack S){
	Stack temp;
	initStack(&temp);
	
	for(; S.top != -1; pop(&S)){
		char c = S.elem[S.top]; //if u have a top function like i do, use char c = top(S);
		push(&temp, c); // just (&temp, top(S))
		printf("%c ", temp.elem[temp.top]);
		
		/*if short cut
		push(&temp, top(S));
		printf("%c ", temp.elem[temp.top]);
		*/
	}
	/* if while loop imo trip then kani
	while(S.top != -1){
		push(&temp, top(S));
		printf("%c ", temp.elem[temp.top]);
		pop(&S);
	}
	*/
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
	insertBottom(&A, 'c');
	display(A);
	return 0;
}
