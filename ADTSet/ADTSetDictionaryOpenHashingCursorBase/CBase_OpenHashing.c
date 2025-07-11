#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
	int data;
	int link;
}NodeType;

typedef struct {
	NodeType arr[MAX];
	int avail;
}Vheap;

typedef int CList;
typedef CList myDict[MAX];
typedef enum {TRUE, FALSE} Boolean;

//init dictionary, and vheap; Vheap memory operations - alloc, dealloc; Open hashing operations

//memory management
void initVheap(Vheap *VH);
int allocSpace(Vheap *VH);
void deallocSpace(Vheap *VH, int elem);

//dictionary functions
void initDict(myDict A);
void insertSorted(myDict A, Vheap *myHeap, int elem);
void deleteElem(myDict A, Vheap *myHeap, int elem);
void display(myDict A, Vheap myHeap);
int hash(int elem);
Boolean isMember(myDict A, Vheap myHeap, int elem);
void displayVHEAP(Vheap VH, CList myList);

int main()
{

	myDict A;
	Vheap VH;
	initVheap(&VH);
	initDict(A);
	
	insertSorted(A, &VH, 8);
	insertSorted(A, &VH, 9);
	insertSorted(A, &VH, 10);
	insertSorted(A, &VH, 100);
	insertSorted(A, &VH, 12);

	Boolean catcher = isMember(A, VH, 8);
	printf("prints 0 if it is an element: %d \n", catcher);
	display(A, VH);
	
	deleteElem(A, &VH, 10);
	printf("\n");
	display(A, VH);
}
//memory management
void initVheap(Vheap *VH)
{
	VH->avail = MAX - 1;
	int x;
	for(x = VH->avail; x >= 0; x--){
		VH->arr[x].link = x - 1;
	}
}
int allocSpace(Vheap *VH)
{
	int temp = VH->avail;
	VH->avail = VH->arr[VH->avail].link;

	return temp;
}

void deallocSpace(Vheap *VH, int elem)
{
	if(elem < MAX) {
		VH->arr[elem].link = VH->avail;
		VH->avail = elem;
	} else {
		printf(" ELEM is outofbounds \n\n");
	}
}

void displayVHEAP(Vheap VH, CList List)
{
	int trav;
	for(trav = List; trav != -1; trav=VH.arr[trav].link){
		printf("[%d] %d \n", trav,VH.arr[trav].link);
	}
}

//dictionary functions

/* Initialize the Dictionary to be empty */
void initDict(myDict A)
{
	int x;
	for(x = 0; x < MAX; x++){
		A[x] = -1;
	}
}

/* Insert unique element in ascending order */
void insertSorted(myDict A, Vheap *myHeap, int elem) //Not allowed to call other functions except hash
{
	int hashVal = elem % MAX;
	int *trav;
	for(trav = &A[hashVal]; *trav != -1 && myHeap->arr[*trav].data < elem; trav = &myHeap->arr[*trav].link){}
	if(*trav == -1 || myHeap->arr[*trav].data != elem){
		int temp = myHeap->avail;
		myHeap->avail = myHeap->arr[temp].link;
		if(temp != -1){
			myHeap->arr[temp].data = elem;
			myHeap->arr[temp].link = *trav;
			*trav = temp;
		}
	}
}

/* Searches for an element within the Dictionary and deletes that elem */
void deleteElem(myDict A, Vheap *myHeap, int elem)
{
	int *trav, hashVal = elem % MAX;
	for(trav = &A[hashVal]; *trav != -1 && myHeap->arr[*trav].data != elem; trav = &myHeap->arr[*trav].link){}
	if(*trav != -1){
		int temp = *trav;
		*trav = myHeap->arr[*trav].link;
		myHeap->arr[temp].link = myHeap->avail;
		myHeap->avail = temp;
	}
}

/* Display the content of the Dictionary  */
void display(myDict A, Vheap myHeap)
{
	int x, trav;
	for(x = 0; x < MAX; x++){
		printf("[%d] -> ", x);
		for(trav = A[x]; trav != -1; trav = myHeap.arr[trav].link){
			printf("%d ", myHeap.arr[trav].data);
		}
		printf("\n");
	}
}

/* Returns the index to search for the element */
int hash(int elem)
{

}

/* Searches for an element in the Dictionary and return TRUE if the element is found */
Boolean isMember(myDict A, Vheap myHeap, int elem)
{
	int trav, hashVal = elem % MAX;
	for(trav = A[hashVal]; trav != -1 && myHeap.arr[trav].data != elem; trav = myHeap.arr[trav].link){}
	return (trav != -1) ? TRUE:FALSE;
}

