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
unsigned int hash(unsigned int val);
void display(Dictionary A);
void deleteStudRec(Dictionary A, unsigned int IDVal);

void display(Dictionary A){
	int x;
	SET trav;
	for(x = 0; x < MAX; x++){
		printf("[%d] -> ", x);
		for(trav = A[x]; trav != NULL; trav = trav->link){
			printf("%d --> ", trav->stud.ID);
		}
		printf("\n");
	}
}

void initDict(Dictionary A){
	int x;
	for(x = 0; x < MAX; x++){
		A[x] = NULL;
	}
}

unsigned int hash(unsigned int val){
	
	unsigned int hashVal = 0;
	for(;val != 0;){
		hashVal += val % 10;
		val /= 10;
	}
	
	return hashVal % MAX;
}

void insertSorted(Dictionary A, studRec val){
	SET *trav, temp;
	unsigned int loc = hash(val.ID);
	for(trav = &A[loc]; *trav != NULL && (*trav)->stud.ID < val.ID; trav = &(*trav)->link){}
	if(*trav == NULL || (*trav)->stud.ID != val.ID){
		temp = (SET)malloc(sizeof(struct node));
		if(temp != NULL){
			temp->stud = val;
			temp->link = *trav;
			*trav = temp;
		}
	}
}

void deleteStudRec(Dictionary A, unsigned int IDVal){
	SET *trav, temp;
	unsigned int loc = hash(IDVal);
	for(trav = &A[loc]; *trav != NULL && (*trav)->stud.ID != IDVal; trav = &(*trav)->link){}
	if(*trav != NULL){
		temp = *trav;
		*trav = (*trav)->link;
		free(temp);
	}
}

int main(){
	
	Dictionary D;
	initDict(D);
	
	studRec studA = {2210, {"Kristian", "Lemuel", 'D'}, "BSCS", 4};
	studRec studB = {2023, {"Borjak", "Diaz", 'W'}, "BSIS", 3};
	studRec studC = {2521, {"Krisostomo", "Waker", 'C'}, "BSIT", 1};

	insertSorted(D, studA);
	insertSorted(D, studB);
	insertSorted(D, studC);
	display(D);
	printf("\nDeleted Value\n");
	deleteStudRec(D, 2023);
	display(D);
	return 0;
	
}
