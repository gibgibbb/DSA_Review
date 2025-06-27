#include <stdio.h>
#include <stdlib.h>

//06/25/25 Pop Quiz 

typedef struct {
    char FName[24];
    char LName[16];
    char MI;
}nameType;

typedef struct {
    nameType name;
    unsigned int id;
    char course[8];
    int year;
}studRec;

typedef struct node {
    studRec data;
    struct node *link;
}*nodePtr;

typedef struct {
    nodePtr P;
    int cnt;
}LIST;

void init(LIST *L);
void display(LIST L);
studRec deleteLast(LIST *L);
void displayStudDel(studRec val); 
void insertSorted(LIST *L, studRec val);
void deleteFirst(LIST *L);
void insertFirst(LIST *L, studRec val);

/*
if u just want to answer the deleteLast and check if it's working, uncomment this function and use it for inserting the data
void insertFirst(LIST *L, studRec value){
    nodePtr temp = malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = value;
        temp->link = L->P;
        L->P = temp;
        L->cnt++;
    }
}
*/

/* Insert the data in a sorted way using the ID  */
void insertSorted(LIST *L, studRec val){
	// place ur code here
}

void displayStudDel(studRec val){
	printf("%10d %10s %10d", val.id, val.course, val.year);
}

// Function Specification
// Deletes the last node from the list and returns its data (a structure containing FName, LName, MI, ID, course, and year).
// If the list is empty, returns a dummy structure with placeholder values and an ID of 0.
// 1 return statement only and no breaks

studRec deleteLast(LIST *L){
    // if you want to answer without the step-by-step, just delete it to challenge yourself
	
	/* Step by Step
	1.) A pointer-to-pointer (trav) is declared to help traverse the list, and a temporary node pointer (temp) is declared to hold the node to be deleted.
	2.) A dummy student record is created with placeholder values to be returned in case the list is empty or no deletion occurs.
	3.) The traversal begins from the head of the list. trav is moved forward until it points to the pointer that holds the last node (the node whose link is NULL).
	4.) Once the last node is located, the function checks if the node exists (i.e., the list is not empty).
	4.1) If the last node is valid: 
		The data from the last node is saved into the dummy variable so it can be returned.
		The pointer temp is assigned the address of the last node.
		The link that points to the last node is updated to NULL, effectively removing the node from the list.
		The memory occupied by the removed node is freed using free(temp).
		The list’s count (cnt) is decremented by 1 to reflect the deletion.
	5.) Finally, the function returns the student record that was stored in dummy — either the deleted node’s data or the initialized dummy data if the list was empty.
	*/
	
	//place ur code here
}

void deleteFirst(LIST *L){
	nodePtr temp;
	if(L->cnt > 0){
		temp = (nodePtr)malloc(sizeof(struct node));
		temp = L->P;
		L->P = L->P->link;
		free(temp);
	}
}

void display(LIST L){
    for(; L.P != NULL; L.P = L.P->link){
        printf("%10d %10s %10d\n", L.P->data.id, L.P->data.course, L.P->data.year);
    }    
}

void init(LIST *L){
    L->P = NULL;
    L->cnt = 0;
}

int main(){
    
    LIST L;
    studRec studA = {{"Kristian", "Diaz", 'W'}, 2210, "BSCS", 3};
    studRec studB = {{"Work", "Pls", 'A'}, 2223, "BSIT", 2};
    studRec studC = {{"AAAA", "RAH", 'D'}, 2200, "BSIS", 4};
    
    init(&L);
    /*Create the function for the insert sorted (remove comment once done)
    insertSorted(&L, studA);
    insertSorted(&L, studB);
    insertSorted(&L, studC);
    */
    
    /* insertFirst(&L, studA); uncomment if you want to use the insertFirst */
    
	display(L);
	printf("\n");
	/*
		Add the function call here
	*/

    /* displayStudDel(studDel); // this will display the deleted/returned data */
    
    return 0;
}
