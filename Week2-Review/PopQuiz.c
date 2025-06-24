#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char FName[24];
	char LName[16];
	char MI;
}nameType;

typedef struct {
	nameType name;
	unsigned int ID;
	char Course[20];
	int Year;
}record;

typedef struct node {
	record StudRec;
	struct node *link;
}*LIST;

void init(LIST *L);
void insertFirst(LIST *L, record data[], int cnt);
void display(LIST L);
nameType isStud(LIST L, unsigned int idNum);

nameType isStud(LIST L, unsigned int idNum){
	
}

void init(LIST *L){
	*L = NULL;
}

void insertFirst(LIST *L, record data[], int cnt){
	LIST temp;
	int x;
	for(x = 0; x < cnt; x++){
		temp = (LIST)malloc(sizeof(struct node));
		if(temp != NULL){
			temp->StudRec = data[x];
			temp->link = *L;
			*L = temp;
		}
	}	
}

void display(LIST L){
	for(; L != NULL; L = L->link){
		printf("%10s %10s %10c %10d %10s %10d\n", L->StudRec.name.FName, L->StudRec.name.LName, L->StudRec.name.MI, L->StudRec.ID, L->StudRec.Course, L->StudRec.Year);
	}
}

int main(){
	
	LIST A;
	record StudA[5] = {{{"Kristian", "Diaz", 'W'}, 2210, "Computer Science", 4}, {{"Kent", "Dulangon", 'C'}, 2204, "Computer Science", 3}, {{"Psalm", "Ipong", 'D'}, 2222, "IT", 3}, {{"Bruh", "Wat", 'S'}, 2213, "Information Science", 4}, {{"Fas", "Da", 'F'}, 2263, "IT", 1}};
	
	init(&A);
	insertFirst(&A, StudA, 5);
	display(A);
	
	return 0;
}
