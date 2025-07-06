#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10

/* ADT Array Version 1 and Operation w Modifications */

/* This is still a version 1 of the array just a structured datatypes for accessing */

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
	studRec stud[MAX];
	int count;
}LIST;

/* Normal Operations */
/* You can modify the return type here (e.g. return the deleted value or return true if the element was inserted) */

void initList(LIST *L); // Given an empty list L, initialize its count to -1 so it is ready for use. (CHECK)
void insertFirst(LIST *L, studRec val); // Given the list L and a student record value, insert value at the front, shifting existing elements to the right, and increment the list count. (CHECK)
void insertLast(LIST *L, studRec val); // Given the list L and a student record val, append val at the end, and increment the list count. (CHECK)

void deleteFirst(LIST *L); // Given the list L, remove the first element (index 0), shift remaining elements left to fill the gap, and decrement the list count. (CHECK)
void deleteLast(LIST *L); // Given the list L, remove the last element, and decrement the list count. (CHECK)

void display(LIST L); // Given the list L, print all student records from index 0 to count-1. (CHECK)
bool findElem(LIST L, char val[]); // Given the list L and a string val, search for a student whose first name matches val. Return true if found, false otherwise. (CHECK)

/* Modified Functions */

void insertAt(LIST *L, studRec val, int pos); // Given the list L, a student record val, and a position pos, insert val at index pos, shift subsequent elements right, and increment count. (CHECK)
void insertFirstUnique(LIST *L, studRec val); // Given the list L and a student record val, insert val at the front only if no existing record has the same ID; shift elements as needed and increment count. (CHECK)
void insertLastUnique(LIST *L, studRec val); // Given the list L and a student record val, append val at the end only if no existing record has the same ID; increment count. (CHECK)
void insertSorted(LIST *L, studRec val);

/* You can modify the return type here (e.g. return the deleted value)*/

void deleteAt(LIST *L, int pos); // Given the list L and a position pos, remove the element at pos, shift subsequent elements left, and decrement count. (CHECK)
void deleteFirstOccurrence(LIST *L, unsigned int IDVal); // Given the list L and an unsigned int IDVal, remove the first record whose id field matches IDVal, shift elements and update count (CHECK)
void deleteAllOccurrences(LIST *L, char courseVal[]); // Given the list L and a string courseVal, remove all records whose course field
   													// matches courseVal, shifting elements left and updating count; 

void displayAllSameYearLevel(LIST L); // Given the list L, print all student records whose yrLevel field matches any value you’re interested in (e.g., group by year level).
int countAllSameCourses(LIST L); // Given the list L, count and return how many student records have the same course field

void initList(LIST *L){ // Working
	L->count = -1;
}

void insertFirst(LIST *L, studRec val){ // Working
	int x;
	if(L->count < MAX){
		for(x = L->count; x >= 0; x--){
			L->stud[x + 1] = L->stud[x];
		}
		L->stud[0] = val;
		L->count++;
	}
}

void deleteFirst(LIST *L){ // Working
	int x;
	if(L->count != -1){
		for(x = 0; x < L->count; x++){
			L->stud[x] = L->stud[x + 1];
		}
		L->count--;
	}
}

void insertLast(LIST *L, studRec val){ // Working
	int x;
	if(L->count < MAX){
		L->stud[++L->count] = val;
	}
}

void deleteLast(LIST *L){ // Working
	if(L->count != -1){
		L->count--;
	}
}

void insertAt(LIST *L, studRec val, int pos){ // Working
	int x;
	if(L->count < MAX){
		if(pos >= 0 && pos <= L->count + 1){
			for(x = L->count; x >= pos; x--){
				L->stud[x + 1] = L->stud[x];
			}
			L->stud[pos] = val;
			L->count++;
		}
	}
}

void insertFirstUnique(LIST *L, studRec val){ // Working
	int x, y;
	if(L->count < MAX){
		for(x = L->count; x >= 0 && strcmp(L->stud[x].name.FN, val.name.FN) != 0; x--){}
		if(x < 0){
			for(y = L->count; y>= 0; y--){
				L->stud[y + 1] = L->stud[y];
			}
			L->stud[0] = val;
			L->count++;
		}
	}
}

void insertLastUnique(LIST *L, studRec val){ // Working
	int x;
	if(L->count < MAX){
		for(x = L->count; x >= 0 && strcmp(L->stud[x].name.FN, val.name.FN) != 0; x--){}
		if(x < 0){
			L->stud[++L->count] = val;
		}
	}
}

void insertSorted(LIST *L, studRec val){
	int x;
	if(L->count < MAX){
		for(x = L->count; x >= 0 && L->stud[x].ID > val.ID; x--){
			L->stud[x + 1] = L->stud[x];
		}
		L->stud[x + 1] = val;
		L->count++;
	}
}

void deleteAt(LIST *L, int pos){ // Working
	int x;
	if(L->count != -1){
		if(pos >= 0 && pos <= L->count){
			for(x = pos; x < L->count; x++){
				L->stud[x] = L->stud[x + 1];
			}
			L->count--;
		}
	}
}

void deleteFirstOccurrence(LIST *L, unsigned int IDVal){ // Working
	int x;
	if(L->count != -1){
		for(x = 0; x <= L->count && L->stud[x].ID != IDVal; x++){}
		if(x <= L->count){
			L->stud[x] = L->stud[x + 1];
			L->count--;
		}
	}
}

void deleteAllOccurrences(LIST *L, char courseVal[]){
	int x, y;
	if(L->count != -1){
		for(x = 0; x <= L->count;){
			if(strcmp(L->stud[x].course, courseVal) == 0){
				for(y = x; y < L->count; y++){
					L->stud[y] = L->stud[y + 1];
				}
				L->count--;
			} else {
				x++;
			}
		}
	}
}

void display(LIST L){ // Working
	int x;
	for(x = 0; x <= L.count; x++){
		printf("%d ", L.stud[x].ID);
	}
}

bool findElem(LIST L, char val[]){ // Working
	int x;
	for(x = L.count; x >= 0 && strcmp(L.stud[x].name.FN, val) != 0 ; x--){}
	return (x >= 0) ? true:false;
}

int main (){
	
	LIST A;
	
	studRec studA = {2210, {"Kristian", "Lemuel", 'W'}, "BSCS", 4};
	studRec studB = {2243, {"Nyohoy", "Gana", 'C'}, "BSCS", 3};
	studRec studC = {2226, {"Yippee", "Work", 'D'}, "BSIS", 4};
	
	initList(&A);
//	insertFirst(&A, studA);
//	insertFirst(&A, studB);
//	insertAt(&A, studC, 0);
	insertSorted(&A, studA);
	insertSorted(&A, studB);
	insertSorted(&A, studC);
//	insertFirstUnique(&A, studC);
//	insertLastUnique(&A, studC);
//	deleteFirst(&A);
//	deleteLast(&A);
//	deleteAt(&A, 0);
//	deleteFirstOccurrence(&A, 2278);
//	deleteAllOccurrences(&A, "BSCS");
	
	display(A);
	
//	printf("\nDeleted\n");
	
//	display(A);
	
//	printf("\n");
//	bool retVal = findElem(A, "Kristian");
//	printf("%d", retVal);
	
	return 0;
}
