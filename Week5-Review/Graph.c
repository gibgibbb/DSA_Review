#include <stdio.h>
#include <stdlib.h>
#define MAX 10 // MAX SIZE OF THE MATRIX (2D ARRAY 10x10)
#define MAX_INT 100 // INFINITY
#define SENTINEL -1 //SENTINEL VALUE

//Adjacency Matrix
typedef int labeltype;
typedef struct {
	labeltype matrix[MAX][MAX]; //2D array of labels (weights)
	int edgeCount; // total nunmber of edges
}labeledAdjMat;

void initMat(labeledAdjMat *M);
void display(labeledAdjMat M);

void initMat(labeledAdjMat *M){
	M->edgeCount = 0;
	int x, y;
	for(x = 0; x < MAX; x++){
		for(y = 0; y < MAX; y++){
			M->matrix[x][y] = SENTINEL;
		}
	}
}

void display(labeledAdjMat M){
	int x, y;
	printf("\n\nTHE ADJACENY MATRIX ::");
 	printf("\n%-8s", "HEAD");
 	printf("%-15s", "TAIL");
 	printf("\n%-8s", "------");
 	printf("\n%-19s", "--------------");
 	
 	for(x = 0; x < MAX; x++){
		printf("\n %c :: ", 'A' + x);
		for(y = 0; y < MAX; y++){
			if(M.matrix[x][y] == SENTINEL){
				printf(" SENTINEL ");
			} else {
				printf("	%2d		", M.matrix[x][y]);
			}
		}
	}
	printf("\n\nNumber of arcs: %d\n\n", M.edgeCount);
}

int main(){
	
	labeledAdjMat A;
	initMat(&A);
	display(A);
	
	return 0;
}
