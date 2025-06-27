#include <stdio.h>
#define MAX 7

// 26/06/25 Start on Virtual Heap

typedef struct {
	char data;
	int link;
}nodeType;

typedef struct {
	nodeType Nodes[MAX];
	int Avail;
}VirtualHeap;

typedef int LIST;

void initVHeap(VirtualHeap *VH);
void initList(LIST *L);
int allocSpace(VirtualHeap *VH);

int allocSpace(VirtualHeap *VH){	
	int temp = VH->Avail;
	if(temp != -1){
		VH->Avail = VH->Nodes[temp].link;
	}
	return temp;	
}

void initList(LIST *L){
	*L = -1;
}

void initVHeap(VirtualHeap *VH){
	VH->Avail = MAX - 1;
	int x;
	for(x = VH->Avail; x >= 0; x--){
		VH->Nodes[x].link = x - 1;
	}
}

int main(){
	
	VirtualHeap A;
	LIST L;
	
	initVHeap(&A);
	initList(&L);
	
	return 0;
}
