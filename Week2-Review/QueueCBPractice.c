#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
	char FN[24], LN[16], MI;
}nameType;

typedef struct {
	nameType studName;
	unsigned int id;
	int yr;
	char course[8];
}record;

typedef struct {
	record studRec;
	int link;
}nodeType;

typedef struct {
	nodeType nodes[MAX];
	int avail;
}*VirtualHeap;

typedef int CList;

typedef struct {
	CList front, rear;
}QueueCB;


int main(){
	
	QueueCB QVH;
	VirtualHeap VH;
	record A = {{"DSA", "PREMID", 'X'}, 2102, 1, "BSIS"};
	record B = {{"KAYA", "RANI", 'D'}, 2005, 2, "BSIT"};
	record C = {{"asjkf", "askfjakjsf", 'F'}, 2232, 4, "BSIS"};
	
	/*
	1.) Initialize the VirtualHeap using initVHeap() function. The function takes the VirtualHeap and set the available nodes to 1 less than the MAX and the link value starts
	from largest to smallest (version 2 if iirc)
	2.) Initialize the Queue using initQueue() function. The function sets the value of front and rear as empty
	3.) Create a display function without using function calls.
	4.) Create the enqueue and dequeue function and add the function call. Use the 3 records above and enqueue them
	5.) Create an insertSorted function without using function call and without "traversing" the virtual heap. The function takes the queue, virtual heap and the record of student

	record studValToAdd = {{"Kristian", "Diaz", 'W'}, 2210, 3, "BSCS"};
	
	*/
	
	
	return 0;
}
