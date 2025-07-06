#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct stack{
	char elem;
	struct stack *link;
}*Stack;

void initStack(Stack *S);
void insertBottom(Stack *S, char val);
void insertFirst(Stack *S, char val);
void deleteFirst(Stack *S);
void display (Stack S);

void initStack(Stack *S){
	*S = NULL;
}

//push
void insertFirst(Stack *S, char val){
	Stack temp = malloc(sizeof(struct stack));
	if(temp != NULL){
		temp->elem = val;
		temp->link = *S;
		*S = temp;
	}
}

void insertBottom(Stack *S, char val){
//	Stack temp = NULL;
//	for(; *S != NULL; deleteFirst(S)){
//		insertFirst(&temp, (*S)->elem);
//	}
//	insertFirst(S, val);
//	for(; temp != NULL; deleteFirst(&temp)){
//		insertFirst(S, temp->elem);
//	}
	Stack temp = malloc(sizeof(struct stack));
	if(temp != NULL){
		temp->elem = val;
		temp->link = *S;
		*S = NULL;
	}
	if(*S != NULL){
		Stack
	}

}

//pop
void deleteFirst(Stack *S){
	if(*S != NULL){
		Stack temp = *S;
		*S = temp->link;
		free(temp);
	}
}

void display(Stack S){
	Stack temp = NULL;
	for(temp = S; temp != NULL; temp = temp->link){
		printf("%c ", temp->elem);
	}
}

int main(){
	
	Stack A;
	initStack(&A);
	
	//push
	insertFirst(&A, 'a');
	insertFirst(&A, 'b');
	insertBottom(&A, 'c');
	
	display(A);
	
	return 0;
}
