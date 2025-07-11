#include <stdio.h>
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

typedef struct node {
	studRec stud;
	struct node *link;
}*SET;

typedef SET Dictionary[MAX];

void initDict(Dictionary A);
void insertSorted(Dictionary A, studRec val);

void initDict(Dictionary A){
	int x;
	for(x = 0; x < MAX; x++){
		A[x] = NULL;
	}
}

void insertSorted(Dictionary A, studRec val){
	
}

int main(){
	
	Dictionary D;
	initDict(D);
	
	return 0;
	
}
