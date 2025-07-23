#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define INF 999
#define SENTINEL -1

typedef int LabelType;
typedef char vertexType;

typedef struct {
	vertexType head, tail;
	int weight;
}edgeType;

typedef struct {
	LabelType matrix[MAX][MAX];
	int edgeCount;
}AdjMat;

typedef struct {
	vertexType adjVertex;
	int weight;
}AdjType;

typedef struct node{
	AdjType info;
	struct node* link;
}*AdjList;

typedef struct {
	AdjList List[MAX];
	int Edgecount;
}AdjListStruct;

void initialize(AdjMat *M);
void displayMat(AdjMat M);
AdjListStruct createAdjList();
void initList(AdjListStruct *L);
void displayAdjList(AdjListStruct L);

void displayAdjList(AdjListStruct L){
	int x;
	AdjList temp;
	
	printf("THE ADJACENCY LIST ::");
	printf("\n%-8s", "VERTEX");
	printf("%-20s", "ADJACENT VERTICES");
	printf("\n%-8s", "------");
	printf("%-19s", "-----------------");
	for(x = 0; x < MAX; x++){
		printf("\n %c :: ", 'A' + x);
		if(L.List[x] == NULL){
			printf(" NULL");
		} else {
			for(temp = L.List[x]; temp != NULL; temp = temp->link){
				printf(" %c (%d)\t", temp->info.adjVertex, temp->info.weight);
			}
		}
	}
}

void initList(AdjListStruct *L){
	int x;
	for(x = 0; x < MAX; x++){
		L->List[x] = NULL;
	}
	L->Edgecount = 0;
}

AdjListStruct createAdjList(){

	AdjListStruct retVal;
	initList(&retVal);
	edgeType data[] = {{'A', 'C', 5}, {'A', 'E', 2}, {'B', 'C', 3}, {'B', 'D', 7}, {'B', 'E', 4}, {'C', 'D', 2}, {'D', 'C', 8}, {'B', 'A', 9}, {'C', 'A', 2}, {'D', 'A', 1}, {'E', 'A', 5}};

	AdjList *trav, temp;
	int x;
	for(x = 0; x < 10; x++){
		for(trav = &(retVal).List[data[x].tail - 'A']; *trav != NULL && (*trav)->info.adjVertex <= data[x].head; trav = &(*trav)->link){}
		if(*trav != NULL && (*trav)->info.adjVertex == data[x].head){
			(*trav)->info.weight = (data[x].weight < (*trav)->info.weight) ? data[x].weight: (*trav)->info.weight;
		} else {
			temp = (AdjList)malloc(sizeof(struct node));
			temp->info.adjVertex = data[x].head;
			temp->info.weight = data[x].weight;
			temp->link = *trav;
			*trav = temp;
		}
		retVal.Edgecount++;
	}
	return retVal;
}

void initialize(AdjMat *M){
	M->edgeCount = 0;
	int x, y;
	for(x = 0; x < MAX; x++){
		for(y = 0; y < MAX; y++){
			M->matrix[x][y] = SENTINEL;
		}
	}
}

void displayMat (AdjMat M){
	int x, y;
	printf("\n\nTHE ADJACENCY MAT ::");
	printf("\n%-8s", "HEAD");
	printf("%-20s", "TAIL");
	printf("\n%-8s", "------");
	printf("%-19s", "-----------------");
	for(x = 0; x < MAX; x++){
		printf("\n %c :: ", 'A' + x);
		for(y = 0; y < MAX; y++){
			if(M.matrix[x][y] == INF){
				printf("%5s", "INF");
			} else {
				printf("%5d", M.matrix[x][y]);
			}
		}
		printf("\n");
	}
	printf("\nThe number of edges is %d", M.edgeCount);
}

int main(){

	AdjListStruct B;
//	initList(&B);
	B = createAdjList();
	displayAdjList(B);

	AdjMat A = {
    	.matrix = {
            { INF,   5,   7, INF, INF },
            {   3,   2, INF, INF, INF },
            { INF, INF, INF, INF,   4 },
            {   1,   6,   5,   3, INF },
            { INF,   4, INF,   3, INF }
        },
    	.edgeCount = 11
    };

	displayMat(A);

	return 0;
}
