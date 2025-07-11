#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ADT List Linked List Implementation Version 2 */

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
}*nodePtr;

typedef struct {
	nodePtr nPtr;
	int count;
}LIST;

/* Normal Operations */
/* You can modify the return type here (e.g. return the deleted value or return true if the element was inserted) */

void initList(LIST *L); // Given an uninitialized list pointer L, allocate/initialize it to NULL 
void insertFirst(LIST *L, studRec val); // Given L and a studRec val, create a new node holding val and link it at the front 
void insertLast(LIST *L, studRec val); // Given L and a studRec val, create a new node holding val and link it at the end 

void deleteFirst(LIST *L); // Given L, remove the node at the front, free its memory, and update the head pointer
void deleteLast(LIST *L); // Given L, remove the node at the end, free its memory, and update the head pointer

void display(LIST L); // Given L, traverse and print every studRec in the list from head to tail
bool findElem(LIST L, char val[]); // Given L and a first-name string val, return true if any node�s data.name.FN matches val

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


int main (){
	
	LIST A;
	
	return 0;
}
