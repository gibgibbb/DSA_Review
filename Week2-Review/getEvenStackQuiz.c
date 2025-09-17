#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node *next;
}*StackPtr;

void initStack(StackPtr *S){
	*S = NULL;
}

void push(StackPtr *S, int val){
	StackPtr temp = malloc(sizeof(struct node));
	if(temp != NULL){
		temp->num = val;
		temp->next = *S;
		*S = temp;
	}
}

void pop(StackPtr *S){
	if(*S != NULL){
		StackPtr temp = *S;
		*S = temp->next;
		free(temp);
	}
}

void display(StackPtr S){
	StackPtr temp = NULL;
	for(temp = S; temp != NULL; temp = temp->next){
		printf("%d ", temp->num);
	}
}

/*

	Given the Stack definition, a function getEven() will accept a stack and extract all even number and add it on a
	newly created stack. The  numbers from the original stack will be deleted. The newly populated stack will be
	then returned to the calling function.  No traversal

_______getEven(){


}

*/

int main(){

	StackPtr S;
	int arr[5] = {5, 10, 21, 3, 6};
	int x;
	initStack(&S);

	for(x = 0; x < 5; x++){
		push(&S, arr[x]);
	}

//	printf("Original stack\n");
//	display(S);

/*

	Place the function call here

*/


	return 0;
}

