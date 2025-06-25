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
    char course[9];
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

studRec deleteLast(LIST *L){
    nodePtr *trav, temp;
    studRec dummy = {{"XXX", "XXX", 'X'}, 0, "XXX", 0};
    for(trav = &L->P; (*trav)->link != NULL; trav = &(*trav)->link){}
    if(*trav != NULL){
        dummy = (*trav)->data;
        temp = *trav;
        *trav = (*trav)->link;
        free(temp);
    }
    return dummy;
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
//    insertSorted(&L, studA);
//    insertSorted(&L, studB);
//    insertSorted(&L, studC);
	insertFirst(&L, studA);
	printf("\n");
    studRec studDel = deleteLast(&L);
    displayStudDel(studDel);
    
    return 0;
}
