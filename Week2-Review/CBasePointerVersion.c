#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//Different Definition/Version for CursorBase 28/06/25

typedef struct {
	char data;
	int link;
}NodeType;

typedef struct node{
	NodeType Nodes[MAX];
	int avail;
}*VirtualHeap;

typedef struct {
	VirtualHeap VHPtr;	
	int List;
}CursorList;

void initHeap(CursorList *CL);

void initHeap(CursorList *CL){
	CL->VHPtr = (VirtualHeap)malloc(sizeof(struct node));
	if(CL->VHPtr != NULL){
		CL->List = -1;
		CL->VHPtr->avail = MAX - 1;
		int x; 
		for(x = CL->VHPtr->avail; x >= 0; x--){ // now it works, this shi crazy
			CL->VHPtr->Nodes[x].link = x - 1;
		}
	}
	/* For some reason, the version 1 works
	CL->VHPtr->avail = 0;
		int x;
		for(x = CL->VHPtr->avail; x < MAX - 1; x++){
			CL->VHPtr->Nodes[x].link = x - 1;
		}
		*/
}


int main(){
	
	CursorList A;
	
	initHeap(&A);
	printf("%d", A.List);
	
	return 0;
}
