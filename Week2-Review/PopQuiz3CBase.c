#include <stdio.h>
#define MAX 3

typedef struct {
	char FName[24];
	char LName[16];
	char Mi;
}Nametype;

typedef struct {
	Nametype data;
	int link;
}Nodetype;

typedef struct {
	Nodetype Nodes[MAX];
	int avail;
}VirtualHeap;

typedef int CList;

void initVheap(VirtualHeap *VH);
void initList(CList *L);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int ndx);
void insertFirst(VirtualHeap *VH, CList *L, Nametype val);
void display(VirtualHeap VH, CList L);
Nametype getLastElem(VirtualHeap VH, CList L); // gets the last elem of the VHeap and return the data to the calling function, if it exists. If it doesn't exist, return a dummy data;

Nametype getLastElem(VirtualHeap VH, CList L){
	Nametype dummy = {"xxx", "xxx", 'x'};
	CList trav = L;
	for(trav = L; VH.Nodes[trav].link != -1; trav = VH.Nodes[trav].link){} // instead of trav != -1 , we check the value of the link to check if it exist.
	if(L != -1){														   // my rule of thumb, if it's deleting or accessing the last elem/check if something exist and it's possible that 
		dummy = VH.Nodes[trav].data;									   // it is in the last node, use the link for the condition checker. (not sure maybe my logic is wrong)
	}
	return dummy;
	
	/* just choose what u prefer and what u understand the most
	for(; VH.Nodes[trav].link != -1; trav = VH.Nodes[trav].link){}
	return (L != -1)? VH.Nodes[trav].data : dummy;
	*/
}

void display(VirtualHeap VH, CList L){
	int trav;
	for(trav = L; trav != -1; trav = VH.Nodes[trav].link){
		printf("%s\n", VH.Nodes[trav].data.FName);
	}
}

void insertFirst(VirtualHeap *VH, CList *L, Nametype val){
	int temp = allocSpace(VH);
	if(temp != -1){
		VH->Nodes[temp].data = val;
		VH->Nodes[temp].link = *L;
		*L = temp;
	}
}

int allocSpace(VirtualHeap *VH){
	int temp = VH->avail;
	if(temp != -1){
		VH->avail = VH->Nodes[temp].link;
	}
	return temp;
}

void deallocSpace(VirtualHeap *VH, int ndx){
	VH->Nodes[ndx].link = VH->avail;
	VH->avail = ndx;
}

void initList(CList *L){
	*L = -1;
}

void initVheap(VirtualHeap *VH){
	VH->avail = MAX - 1;
	int x;
	for(x = VH->avail; x >= 0; x--){
		VH->Nodes[x].link = x - 1;
	}
}

int main(){
	
	VirtualHeap A;
	CList CL;
	
	initList(&CL);
	initVheap(&A);
	
	Nametype studA = {"Kristian", "Diaz", 'W'};
    Nametype studB = {"Work", "Pls", 'A'};
    Nametype studC = {"AAAA", "RAH", 'D'};
    
    insertFirst(&A, &CL, studA);
	insertFirst(&A, &CL, studB);
	insertFirst(&A, &CL, studC);
	
	display(A, CL);
	
	Nametype catcher = getLastElem(A, CL);
	printf("\nJust to check if it works\n%s", catcher.FName);
	
	return 0;
}
