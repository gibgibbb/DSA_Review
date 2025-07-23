#include <stdio.h>
#include <stdlib.h>
#include <limit.h>
#include <stdbool.h>
#define MAX 5
#define SENTINEL -1;


typedef int AdjMat[MAX][MAX];
typedef char vertexType;

int *DijkstraMat(vertextType src, AdjMat M);

int *DijkstraMat(vertextType src, AdjMat M){
	Boolean visited[MAX] = {FALSE};
	int *D = (int*)malloc(sizeof(int)*MAX);
	if(D != NULL){
		int i;
		for(i = 0; i < MAX; i++){
			D[i] = SENTINEL;
		}
		D[src - 'A'] = 0;
		int x, y;
		for(x = 0; x < MAX; x++){
			int min = INT_MAX, minNdx;
			for(y = 0; y < MAX; y++){
				if(visited[x] == FALSE && D[x] < min){
					minNdx = x;
					min = D[minNdx];
				}
			}
			visited[minNdx] = TRUE;
			for(i = 0; i < MAX; i++){
				if(visited[i] == FALSE && M[minNdx][a] != SENTINEL && M[minNdx][a] + D[minNdx] < D[i]){
					D[i] = M[minNdx][a] + D[minNdx];
				}
			}
		}
	}
	return D;
}

int main(){
	
	AdjMat A;
	int *catcher = DijkstraMat('B', A);
	
	return 0;
}
