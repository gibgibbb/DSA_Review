#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

void initCList(CLIST *CL);
int allocSpace(CLIST *CL);
void deallocSpace(CLIST *CL, int ndx);

/* Simple Operations */
void insertFirst(CLIST *CL, studRec val);
void insertLast(CLIST *CL, studRec val);

void deleteFirst(CLIST *CL);
void deleteLast(CLIST *CL);


/* Modified */
void insertAt(CLIST *CL, studRec val, int pos);

void insertAt(CLIST *CL, studRec val, int pos){
	int *trav, temp, count;
	for(trav = &CL->count, count = 0; *trav != -1 && count < pos; trav = &CL->vPtr->nodes[*trav].link, count++){}
	if(pos <= count && CL->vPtr->avail != -1){
		temp = allocSpace(CL);
		CL->vPtr->nodes[temp].stud = val;
		CL->vPtr->nodes[temp].link = *trav;
		*trav = temp;
	}
}

void insertLast(CLIST *CL, studRec val){
	int *trav, temp;
	for(trav = &CL->count; *trav != -1; trav = &CL->vPtr->nodes[*trav].link){}
	temp = CL->vPtr->avail;
	if(temp != -1){
		CL->vPtr->avail = CL->vPtr->nodes[temp].link;
		CL->vPtr->nodes[temp].stud = val;
		CL->vPtr->nodes[temp].link = *trav;
		*trav = temp;
	}
}

void insertFirst(CLIST *CL, studRec val){
	int temp = CL->vPtr->avail;
	if(temp != -1){
		CL->vPtr->avail = CL->vPtr->nodes[temp].link;
		CL->vPtr->nodes[temp].stud = val;
		CL->vPtr->nodes[temp].link = CL->count;
		CL->count = temp;
	}
}

void deleteFirst(CLIST *CL){
	if(CL->count != -1){
		int temp = CL->count;
		CL->count = CL->vPtr->nodes[temp].link;
		deallocSpace(CL, temp);
	}
}

void initCList(CLIST *CL){
	CL->vPtr = malloc(sizeof(struct vheap));
	if(CL->vPtr != NULL){
		CL->count = -1;
		CL->vPtr->avail = MAX -1;
		int x;
		for(x = CL->vPtr->avail; x >= 0; x--){
			CL->vPtr->nodes[x].link = x - 1;
		}
		
	}
}

int allocSpace(CLIST *CL){
	int temp = CL->vPtr->avail;
	if(temp != -1){
		CL->vPtr->avail = CL->vPtr->nodes[temp].link;
	}
	return temp;
}

void deallocSpace(CLIST *CL, int ndx){
	CL->vPtr->nodes[ndx].link = CL->vPtr->avail;
	CL->vPtr->avail = ndx;
}

void display(CLIST CL){
	int x;
	for(x = CL.count; x != -1; x = CL.vPtr->nodes[x].link){
		printf("%s ", CL.vPtr->nodes[x].stud.name.FN);
	}
}

int main(){
	
	studRec studA = {2210, {"Kristian", "Lemuel", 'W'}, "BSCS", 4};
	studRec studB = {2243, {"Nyohoy", "Gana", 'C'}, "BSIT", 3};
	studRec studC = {2226, {"Yippee", "Work", 'D'}, "BSIS", 4};
	studRec studD = {2210, {"abhjewjf", "asdasf", 'F'}, "BSIT", 1};
	
	CLIST C;
	initCList(&C);

	insertFirst(&C, studA);
	insertFirst(&C, studB);
	insertFirst(&C, studC);
	insertFirst(&C, studD);

//	insertLast(&C, studA);
//	insertLast(&C, studB);
//	insertLast(&C, studC);
//	insertLast(&C, studD);
//	insertAt(&C, studD, 1);

	deleteFirst(&C);
	
	display(C);
	
	return 0;
}
