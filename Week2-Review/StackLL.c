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
//	Stack temp;
//	temp = NULL;
//	for(; *S != NULL; deleteFirst(S)){
//		insertFirst(&temp, (*S)->elem);
//	}
//	insertFirst(S, val);
//	for(; temp != NULL; deleteFirst(&temp)){
//		insertFirst(S, temp->elem);
//	}
	Stack temp = NULL;
 	for(;*S != NULL;){
		Stack temp2 = *S;
		char v = temp2->elem;
		*S = temp2->link;
		free(temp2);

		Stack temp3 = malloc(sizeof(struct stack));
		temp3->elem = v;
		temp3->link = temp;
		temp = temp3;
	}
	temp = malloc(sizeof(struct stack));
	if(temp != NULL){
		newNode->elem = val;
		newNode->link = NULL;
		*S = newNode;
	}
	for(;temp != NULL;){
		Stack temp2 = temp;
		char v = temp2->elem;
		temp = temp2->link;
		free(temp2);

		Stack temp3 = malloc(sizeof(struct stack));
		temp3->elem = v;
		temp3->link = *S;
		*S = temp3;
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
//	insertFirst(&A, 'a');
//	insertFirst(&A, 'b');
	insertBottom(&A, 'c');
	insertBottom(&A, 'd');
	
	display(A);
	
	return 0;
}
