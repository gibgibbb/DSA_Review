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
void insertFirst(LIST *L, studRec value);
void display(LIST L);
studRec deleteLast(LIST *L);
void displayStudDel(studRec value);
void insertSorted(LIST *L, studRec val);
void deleteFirst(LIST *L);

void insertSorted(LIST *L, studRec val){
	nodePtr *trav, temp;
	for(trav = &L->P; *trav!= NULL && (*trav)->data.id < val.id; trav = &(*trav)->link){}
	temp = malloc(sizeof(struct node));
	if(temp != NULL){
		temp->data = val;
		temp->link = *trav;
		*trav = temp;
		L->cnt++;
	}
}

void displayStudDel(studRec value){
	printf("%10d %10s %10d", value.id, value.course, value.year);
}

// What I noticed (maybe i am wrong)
// When deleting the last element of a list, we use (*trav)->link instead of (*trav) in the condition

studRec deleteLast(LIST *L){
    nodePtr *trav, temp; 												// why nodePtr *trav and not LIST *trav? remember that LIST is a list (LIST *L is a pointer to a structure) and we have to use a pointer to a pointer to a node (trav = &L->P) where trav is now pointing to the address of the pointer
    studRec dummy = {{"XXX", "XXX", 'X'}, 0, "XXX", 0}; 				// initialized a value (just a checker)
    for(trav = &L->P; (*trav)->link != NULL; trav = &(*trav)->link){} 	// instead of *trav != NULL, we check the value of (*trav)->link since if we use *trav, we'd reach the end of the list of nodes and *trav == NULL which will not execute the if statement below
    if(*trav != NULL){													// if we reached the end, we delete the data
        dummy = (*trav)->data;											// save the data from the last node so we can return it.
        temp = *trav;													// temp holds the node that will be deleted
        *trav = (*trav)->link;											// *trav gets NULL
        free(temp);														// deallocate the space
        L->cnt--;
    }
    return dummy;
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

void insertFirst(LIST *L, studRec value){
    nodePtr temp = malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = value;
        temp->link = L->P;
        L->P = temp;
        L->cnt++;
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
    insertSorted(&L, studA);
    insertSorted(&L, studB);
    insertSorted(&L, studC);
	insertFirst(&L, studA);
//	display(L);
	printf("\n");
	studRec studDel = deleteLast(&L);
    displayStudDel(studDel);
//    deleteFirst(&L);
    
    return 0;
}
