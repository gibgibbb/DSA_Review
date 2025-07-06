#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
	char FN[24], LN[16], MI;
}nameType;

typedef struct {
	unsigned int ID;
	nameType name;
	char course[8];
	int yrLevel;
}studRec;

typedef struct {
	studRec stud;
	int link;
}nodeType;

typedef struct vheap{
	nodeType nodes[MAX];
	int avail;
}*VHeap;

typedef struct {
	VHeap vPtr;
	int count;
}CLIST;

void init(CLIST *A){
	A->count = 0;
}

int main(){
	
	CLIST A;
	init(&A);

	return 0;
}
