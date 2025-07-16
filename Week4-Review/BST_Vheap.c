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

void initClistHeap(Clist *L, BSTHeap *BST){
	*L = -1;
	BST->avail = MAX - 1;
	int x;
	for(x = BST->avail; x >= 0; x--){
		BST->nodes[x].lc = -1;
		BST->nodes[x].rc = (x > 0) ? x - 1: -1;
	}
}

void display(BSTHeap BST){
	int x;
	printf("LC & RC\n");
	for(x = 0; x < MAX; x++){
	//	printf("\n%10s%10s\n", BST.nodes[x].elem.nickname, BST.nodes[x].elem.ID);
		printf("%d %d\n", BST.nodes[x].lc, BST.nodes[x].rc);
	}
}

int main(){
	
	Clist L;
	BSTHeap BSTH;
	initClistHeap(&L, &BSTH);
	display(BSTH);
	return 0;
}
