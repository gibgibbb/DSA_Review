#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

typedef char STRING[15];
typedef struct {
	char ID[5];
	STRING nickname;
}elemType;

typedef struct {
	elemType data;
	int lc, rc;
}nodeType;

typedef struct {
	nodeType nodes[MAX];
	int avail;
}BSTHeap;

typedef int Clist;

void initClistHeap(Clist *L, BSTHeap *BST);
void display(BSTHeap BST, Clist L);
void insert(BSTHeap *BST, Clist *L, elemType val);
int allocSpace(BSTHeap *BST);
void deallocSpace(BSTHeap *BST, int pos);
void deleteElem(BSTHeap *BST, Clist *L, elemType val);

void deallocSpace(BSTHeap *BST, int pos){
	BST->nodes[pos].lc = -1;
	BST->nodes[pos].rc = BST->avail;
	BST->avail = pos;
}

void deleteElem(BSTHeap *BST, Clist *L, elemType val){
	int *trav;
	for(trav = L; *trav != -1 && strcmp(BST->nodes[*trav].data.ID, val.ID) != 0;){
		trav = (strcmp(val.ID, BST->nodes[*trav].data.ID) < 0) ? &(BST->nodes[*trav].lc) : &(BST->nodes[*trav].rc);
	}
	if(*trav != -1){
		int temp = *trav;
		if(BST->nodes[temp].lc != -1 && BST->nodes[temp].rc != -1){
			int *trav2;
			for(trav2 = &BST->nodes[temp].rc; *trav2 != -1 && BST->nodes[*trav2].lc != -1; trav2 = &BST->nodes[*trav2].lc){}
			BST->nodes[temp].data = BST->nodes[*trav2].data;
			temp = *trav2;
			*trav2 = BST->nodes[temp].rc;
		} else {
			*trav = (BST->nodes[temp].lc != -1) ? BST->nodes[temp].lc : BST->nodes[temp].lc;
		}
		deallocSpace(BST, temp);
		printf("Deleted \t%-10s\t%-10s\n", BST->nodes[temp].data.ID, BST->nodes[temp].data.nickname);
	}
}



int allocSpace(BSTHeap *BST){
	int temp = BST->avail;
	if(temp != -1){
		BST->avail = BST->nodes[temp].rc;
	}
	return temp;
}

void insert(BSTHeap *BST, Clist *L, elemType val){
	int *trav, temp;
	if(BST->avail != -1){
		for(trav = L; *trav != -1 && strcmp(BST->nodes[*trav].data.ID, val.ID) != 0;){
			trav = (strcmp(val.ID, BST->nodes[*trav].data.ID) < 0) ? &(BST->nodes[*trav].lc) : &(BST->nodes[*trav].rc);
		}
		if(*trav == -1){
			int temp = allocSpace(BST);
			if(temp != -1){
				BST->nodes[temp].data = val;
				BST->nodes[temp].lc = BST->nodes[temp].rc = -1;
				*trav = temp;
			}
		}
	}
}

void initClistHeap(Clist *L, BSTHeap *BST){
	*L = -1;
	BST->avail = MAX - 1;
	int x;
	for(x = BST->avail; x >= 0; x--){
		BST->nodes[x].lc = -1;
		BST->nodes[x].rc = (x > 0) ? x - 1: -1;
	}
}


//preorder
void display(BSTHeap BST, Clist L){
	if(L != -1){
		printf("\t%-10s\t%-10s\n", BST.nodes[L].data.ID, BST.nodes[L].data.nickname);
		display(BST, BST.nodes[L].lc);
		display(BST, BST.nodes[L].rc);
	}
}

int main(){
	
	Clist L;
	BSTHeap BSTH;
	elemType A = {"888", "Gibgib"};
	elemType B = {"223", "Sova"};
	elemType C = {"967", "Astra"};
	initClistHeap(&L, &BSTH);
	insert(&BSTH, &L, A);
	insert(&BSTH, &L, B);
	insert(&BSTH, &L, C);
	display(BSTH, L);
	deleteElem(&BSTH, &L, A);
	printf("\n");
	display(BSTH, L);
	return 0;
}
