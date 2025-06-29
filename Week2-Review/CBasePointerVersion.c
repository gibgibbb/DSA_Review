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
void deallocSpace(CursorList *CL, int pos); // pass by address
void deleteFirst(CursorList *CL); // pass by address

// VHeap Function
void deallocSpace(CursorList *CL, int pos){
	CL->VHPtr->Nodes[pos].link = CL->VHPtr->avail;
	CL->VHPtr->avail = pos;
}

int allocSpace(CursorList *CL){
	int temp = CL->VHPtr->avail;
	if(temp != -1){
		CL->VHPtr->avail = CL->VHPtr->Nodes[temp].link;
	}
	return temp;
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
	/* For some reason, the version 1 works and the version 2 doesn't // disregard this comment 
	CL->VHPtr->avail = 0;    
		int x;
		for(x = CL->VHPtr->avail; x < MAX - 1; x++){
			CL->VHPtr->Nodes[x].link = x - 1;
		}
		*/
}

// display function

void display(CursorList CL){
	int x;
	for(x = CL.List; x != -1; x = CL.VHPtr->Nodes[x].link){
		printf("%c ", CL.VHPtr->Nodes[x].data);
	}	
}

// Data Manipulation Functions

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

void deleteFirst(CursorList *CL){
	if(CL->List != -1){
		int temp = CL->List;
		CL->List = CL->VHPtr->Nodes[temp].link;
		deallocSpace(CL, temp);
	}
}


int main(){
	
	CursorList A;
	
	initHeap(&A);
	insertFirst(&A, 'u');
	insertFirst(&A, 's');
	insertFirst(&A, 'c');
	display(A);
	printf("\n");
	deleteFirst(&A);
	display(A);
	
	return 0;
}
