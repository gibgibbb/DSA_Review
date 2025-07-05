#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

/* ADT Array Version 2 and Operation w Modifications */

/* This is still a version 2 of the array just a structured datatypes for accessing */

typedef struct {
	char FN[24], LN[16], MI;
}nameType;

typedef struct {
	unsigned int ID;
	nameType name;
	char course[8];
	int yrLevel;
}studRec;

typedef struct list{
	studRec stud[MAX];
	int count;
}*LIST;

/* Normal Operations */
/* You can modify the return type here (e.g. return the deleted value) */

void initList(LIST *L); // Given an empty list L, initialize its count to -1 so it is ready for use.
void insertFirst(LIST *L, studRec val); // Given the list L and a student record value, insert value at the front, shifting existing elements to the right, and increment the list count.
void insertLast(LIST *L, studRec val); // Given the list L and a student record val, append val at the end, and increment the list count.

void deleteFirst(LIST *L); // Given the list L, remove the first element (index 0), shift remaining elements left to fill the gap, and decrement the list count.
void deleteLast(LIST *L); // Given the list L, remove the last element, and decrement the list count.

void display(LIST L); // Given the list L, print all student records from index 0 to count-1.
bool findElem(LIST L, char val[]); // Given the list L and a string val, search for a student whose first name matches val. Return true if found, false otherwise.

/* Modified Functions */

void insertAt(LIST *L, studRec val, int pos); // Given the list L, a student record val, and a position pos, insert val at index pos, shift subsequent elements right, and increment count. 
void insertFirstUnique(LIST *L, studRec val); // Given the list L and a student record val, insert val at the front only if no existing record has the same ID; shift elements as needed and increment count.
void insertLastUnique(LIST *L, studRec val); // Given the list L and a student record val, append val at the end only if no existing record has the same ID; increment count.

/* You can modify the return type here (e.g. return the deleted value)*/

void deleteAt(LIST *L, int pos);
void deleteFirstOccurence(LIST *L, unsigned int IDVal); // Given the list L and a position pos, remove the element at pos, shift subsequent elements left, and decrement count. 
void deleteAllOccurence(LIST *L, char courseVal[]); // Given the list L and a string courseVal, remove all records whose course field
   													// matches courseVal, shifting elements left and updating count; return the number
   													// of deleted entries

void displayAllSameYearLevel(LIST L); // Given the list L, print all student records whose yrLevel field matches any value you’re interested in (e.g., group by year level).
int countAllSameCourses(LIST L); // Given the list L, count and return how many student records have the same course field

int main(){
	
	
	return 0;
}
