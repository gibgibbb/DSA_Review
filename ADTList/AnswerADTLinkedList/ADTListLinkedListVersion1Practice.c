#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* ADT List Linked List Implementation Version 1 */

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
}*LIST;

/* Normal Operations */
/* You can modify the return type here (e.g. return the deleted value or return true if the element was inserted) */

void initList(LIST *L); // Given an uninitialized list pointer L, allocate/initialize it to NULL 
void insertFirst(LIST *L, studRec val); // Given L and a studRec val, create a new node holding val and link it at the front 
void insertLast(LIST *L, studRec val); // Given L and a studRec val, create a new node holding val and link it at the end 

void deleteFirst(LIST *L); // Given L, remove the node at the front, free its memory, and update the head pointer
void deleteLast(LIST *L); // Given L, remove the node at the end, free its memory, and update the head pointer

void display(LIST L); // Given L, traverse and print every studRec in the list from head to tail
bool findElem(LIST L, char val[]); // Given L and a first-name string val, return true if any node’s data.name.FN matches val

/* Modified Functions */

void insertAt(LIST *L, studRec val, int pos); // Given L, a studRec val, and a 0-based position pos, insert a new node at index pos 
void insertFirstUnique(LIST *L, studRec val); // Given L and a studRec val, insert at front only if no existing node has the same ID 
void insertLastUnique(LIST *L, studRec val); // Given L and a studRec val, insert at end only if no existing node has the same ID 

/* You can modify the return type here (e.g. return the deleted value) */

void deleteAt(LIST *L, int pos); // Given L and a 0-based position pos, remove the node at pos and free its memory
void deleteFirstOccurrence(LIST *L, unsigned int IDVal); // Given L and an unsigned IDVal, remove the first node whose data.ID == IDVal 
void deleteAllOccurrences(LIST *L, char courseVal[]); // Given L and a course string courseVal, remove *all* nodes whose data.course matches 

void displayAllSameYearLevel(LIST L, int yr); //  Given L and an integer yr, traverse and print all records whose data.yrLevel == yr 
int countAllSameCourses(LIST L, char courseVal[]); // Given L and a course string courseVal, count and return how many nodes match that course


void initList(LIST *L){
	*L = NULL;
}

void insertFirst(LIST *L, studRec val){ // Working
	LIST temp = malloc(sizeof(struct node));
	if(temp != NULL){
		temp->stud = val;
		temp->link = *L;
		*L = temp;
	}
}

void insertLast(LIST *L, studRec val){ // Working
	LIST *trav, temp;
	for(trav = L; *trav != NULL; trav = &(*trav)->link){}
	temp = malloc(sizeof(struct node));
	if(temp != NULL){
		temp->stud = val;
		temp->link = *trav;
		*trav = temp;
	}
}


void insertFirstUnique(LIST *L, studRec val){ // Working
	LIST trav, temp;
	for(trav = *L; trav != NULL && trav->stud.ID != val.ID; trav = trav->link){}
	if(trav == NULL){
		temp = malloc(sizeof(struct node));
		temp->stud = val;
		temp->link = *L;
		*L = temp;
	}
}

void insertLastUnique(LIST *L, studRec val){ // Working
	LIST *trav, temp;
	for(trav = L; *trav != NULL && (*trav)->stud.ID != val.ID; trav = &(*trav)->link){}
	if(*trav == NULL){
		temp = malloc(sizeof(struct node));
		temp->stud = val;
		temp->link = *trav;
		*trav = temp;
	}
}

void insertAt(LIST *L, studRec val, int pos){ // Working
	int x;
	LIST *trav, temp;
	for(trav = L, x = 0; x < pos && *trav != NULL; trav = &(*trav)->link, x++){}
	temp = malloc(sizeof(struct node));
	if(temp != NULL){
		temp->stud = val;
		temp->link = (*trav);
		*trav = temp;
	}
}

void deleteAt(LIST *L, int pos){
	int x;
	LIST *trav, temp;
	if(*L != NULL){
		for(trav = L, x = 0; x < pos && (*trav)->link != NULL; trav = &(*trav)->link, x++){}
		temp = *trav;
		*trav = temp->link;
		free(temp);
 	}
}

void deleteFirstOccurrence(LIST *L, unsigned int IDVal){
	LIST *trav, temp;
	for(trav = L; (*trav)->link != NULL && (*trav)->stud.ID != IDVal; trav = &(*trav)->link){}
	if(*trav != NULL){
		temp = *trav;
		*trav = temp->link;
		free(temp);
	}
}

void deleteAllOccurrences(LIST *L, char val[]){
	LIST *trav, temp;
	for(trav = L; *trav != NULL;){
		if(strcmp((*trav)->stud.course, val) == 0){
			temp = *trav;
			*trav = temp->link;
			free(temp);
		} else {
			trav = &(*trav)->link;
		}
	}
}

void deleteFirst(LIST *L){ // Working
	LIST temp;
	if(*L != NULL){
		temp = *L;
		*L = temp->link;
		free(temp);
	}
}

void deleteLast(LIST *L){ // Working
	LIST *trav, temp;
	if(*L != NULL){
		for(trav = L; (*trav)->link != NULL; trav = &(*trav)->link){}
		temp = *trav;
		*trav = temp->link;
		free(temp);
	}
}

void display(LIST L){ // Working
	for(; L != NULL; L= L->link){
		printf("%s ", L->stud.name.FN);
	}
}

int main (){
	
	LIST A;
	initList(&A);
	
	studRec studA = {2210, {"Kristian", "Lemuel", 'W'}, "BSCS", 4};
	studRec studB = {2243, {"Nyohoy", "Gana", 'C'}, "BSIT", 3};
	studRec studC = {2226, {"Yippee", "Work", 'D'}, "BSIS", 4};
	studRec studD = {2210, {"abhjewjf", "asdasf", 'F'}, "BSIT", 1};
	
//	insertLast(&A, studA);
//	insertLast(&A, studB);
//	insertLast(&A, studC);

//	insertFirst(&A, studA);
//	insertFirst(&A, studB);
//	insertFirst(&A, studC);
//	insertFirst(&A, studD);
//	insertAt(&A, studD, 0);
	insertFirstUnique(&A, studD);
	insertFirstUnique(&A, studB);
//	insertLastUnique(&A, studD);
	
//	deleteFirst(&A);
//	deleteLast(&A);
//	deleteAt(&A, 0);
//	deleteFirstOccurrence(&A, 2210);
//	deleteAllOccurrences(&A, "BSCS");
	
	display(A);
	return 0;
}
