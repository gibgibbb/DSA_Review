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

// general rule
// pass by address if a value will be changed

void initHeap(CursorList *CL); // pass by address
void insertFirst(CursorList *CL, char val);
void display(CursorList CL); // pass by address
int allocSpace(CursorList *CL); // pass by address

int allocSpace(CursorList *CL){
	int temp = CL->VHPtr->avail;
	if(temp != -1){
		CL->VHPtr->avail = CL->VHPtr->Nodes[temp].link;
	}
	return temp;
}

void display(CursorList CL){
	int x;
	for(x = CL.List; x != -1; x = CL.VHPtr->Nodes[x].link){
		printf("%c ", CL.VHPtr->Nodes[x].data);
	}	
}

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

void insertFirst(CursorList *CL, char val){
	if(CL->VHPtr->avail != -1){
		int temp = allocSpace(CL);
		if(temp != -1){
			CL->VHPtr->Nodes[temp].data = val;
			CL->VHPtr->Nodes[temp].link = CL->List;
			CL->List = temp; 
		}
	}
}


int main(){
	
	CursorList A;
	
	initHeap(&A);
	insertFirst(&A, 'u');
	insertFirst(&A, 's');
	insertFirst(&A, 'c');
	display(A);
	
	return 0;
}
