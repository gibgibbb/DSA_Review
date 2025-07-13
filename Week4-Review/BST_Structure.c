#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student Record Structure (similar to the image)
typedef struct {
    char FName[24], LName[16], MI;
} nametype;

typedef struct {
    unsigned int ID;
    nametype SName;
    char course[8];
    int yr;
} studRec;

// Tree Node using List of Children
typedef struct node{
    studRec data;
    struct node *LC;   // Points to first child
    struct node *RC;  // Points to next sibling
} TreeNode, *Tree;

void init(Tree *T);
void insertTree(Tree *T, studRec val);

void init(Tree *T){
	*T = NULL;
}

void insertTree(Tree *T, studRec val){
	Tree *trav, temp;
	for(trav = T; *trav != NULL && (*trav)->data.ID != val.ID;){
		trav = (val.ID < (*trav)->data.ID)? &(*trav)->LC : &(*trav)->RC;
	}
	if(*trav == NULL){
		temp = (Tree)malloc(sizeof(struct node));
		if(temp != NULL){
			temp->data = val;
			temp->LC = temp->RC = NULL;
			*trav = temp;
		}
	}
}

int main(){
	
	Tree T;
	studRec A = {2210, {"Kristian", "Lemuel", 'W'}, "BSCS", 4};
	studRec B = {2102, {"ASDASD", "ASDDG", 'F'}, "BSIS", 4};
	studRec C = {2240, {"Kris", "Le", 'D'}, "BSIT", 3};
	
	
	init(&T);
	insertTree(&T, A);
	insertTree(&T, B);
	insertTree(&T, C);
	
	return 0;
}
