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

}

/* Insert unique element in ascending order */
void insertSorted(myDict A, Vheap *myHeap, int elem) //Not allowed to call other functions except hash
{

}

/* Searches for an element within the Dictionary and deletes that elem */
void deleteElem(myDict A, Vheap *myHeap, int elem)
{

}

/* Display the content of the Dictionary  */
void display(myDict A, Vheap myHeap)
{

}

/* Returns the index to search for the element */
int hash(int elem)
{

}

/* Searches for an element in the Dictionary and return TRUE if the element is found */
Boolean isMember(myDict A, Vheap myHeap, int elem)
{

}










