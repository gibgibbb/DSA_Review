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
	newly created stack. The even numbers from the original stackwill be delete. The newly populated stack will be
	then returned to the calling function.  No traversal

_______  StackPtr getEven(StackPtr *S){

	StackPtr retVal = NULL;

	for(; *S != NULL;){
		if((*S)->num % 2 == 0){
			StackPtr holder = *S;
			int v = holder->num;
			*S = holder->next;
			free(holder);

			StackPtr holder2 = malloc(sizeof(struct node));
			holder2->num = v;
			holder2->next = retVal;
			retVal = holder2;
		} else {
			*S = (*S)->next;
		}
	}
	return retVal;

}

*/

StackPtr getEven(StackPtr *S){

	StackPtr retVal = NULL;

	for(; *S != NULL;){
		if((*S)->num % 2 == 0){
			StackPtr holder = *S;
			int v = holder->num;
			*S = holder->next;
			free(holder);

  			StackPtr holder2 = malloc(sizeof(struct node));
			holder2->num = v;
			holder2->next = retVal;
			retVal = holder2;
		} else {
			*S = (*S)->next;
		}
	}
	return retVal;

}


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

	StackPtr evenStack = getEven(&S);
	printf("\nEven stack\n");
	display(evenStack);
	
	printf("\nOriginal stack\n");
	display(S);

	return 0;
}

