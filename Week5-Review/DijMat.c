#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 5
#define SENTINEL -1
#define INF INT_MAX


typedef int AdjMat[MAX][MAX];
typedef char vertexType;
typedef enum {FALSE, TRUE
}Boolean;

int *DijkstraMat(vertexType src, AdjMat M);

int *DijkstraMat(vertexType src, AdjMat M){
	Boolean visited[MAX] = {FALSE};
	int *D = (int*)malloc(sizeof(int)*MAX);
	if(D != NULL){
		int i;
		for(i = 0; i < MAX; i++){
			D[i] = M[src - 'A'][i];
		}
		D[src - 'A'] = 0;
		int x, y;
		for(x = 0; x < MAX; x++){
			int min = INF, minNdx;
			for(y = 0; y < MAX; y++){
				if(visited[y] == FALSE && D[y] < min){
					minNdx = y;
					min = D[minNdx];
				}
			}
			visited[minNdx] = TRUE;
			for(i = 0; i < MAX; i++){
				if(visited[i] == FALSE && M[minNdx][i] != SENTINEL && M[minNdx][i] + D[minNdx] < D[i]){
					D[i] = M[minNdx][i] + D[minNdx];
				}
			}
		}
	}
	return D;

/* 2nd Dij  */
//	int *D, S[MAX], Scount = 0, x, y, i, w, min = INF;
//	int V[MAX] = {0,1,2,3,4};
//	D = (int*)malloc(sizeof(int) * MAX);
//	if(D != NULL){
//		S[0] = src - 'A';
//		Scount++;
//		for(i = 0; i < MAX; i++){
//			D[i] = M[src - 'A'][i];
//		}
//		D[src - 'A'] = 0;
//		for(i = 1; i < MAX; i++){
//			for(x = 0; x < MAX; x++){
//				for(y = 0; y < Scount && V[x] != S[y]; y++){}
//				if(y == Scount && D[V[x]] < min){
//					min = D[V[x]];
//					w = V[x];
//				}
//			}
//			S[Scount] = w;
//			Scount++;
//			for(x = 0; x < MAX; x++){
//				for(y = 0; y < Scount && V[x] != S[y]; y++){}
//				if(y == Scount){
//					if(D[V[x]] > D[w] + M[w][V[x]]){
//						D[V[x]] = D[w] + M[w][V[x]];
//					}
//				}
//			}
//			min = INF;
//		}
//	}
//	return D;

/* 3rd Dij */
//	int *D, S[MAX], x, y, i, min, u;
//	D = (int*)malloc(sizeof(int) * MAX);
//	if(D != NULL){
//		for(i = 0; i < MAX; i++){
//			D[i] = INF;
//			S[i] = 0;
//		}
//		D[src - 'A'] = 0;
//		for(x = 0; x < MAX; x++){
//			min = INF;
//			u = -1;
//			for(y = 0; y < MAX; y++){
//				if(S[y] == 0 && D[y] < min){
//					min = D[y];
//					u = y;
//				}
//			}
//			if( y != -1){
//				S[y] = 1;
//			}
//			for(y = 0; y < MAX; y++){
//				if(S[y] != -1 && D[u] != INF && D[u] + M[u][y] < D[y]){
//					D[y] = D[u] + M[u][y];
//				}
//			}
//		}
//	}
//	return D;
}

int main(){
	
	AdjMat A = {
        { INF,   5,   7, INF, INF },
        {   3,   2, INF, INF, INF },
        { INF, INF, INF, INF,   4 },
        {   1,   6,   5,   3, INF },
        { INF,   4, INF,   3, INF }
    };
	int *catcher = DijkstraMat('A', A);
	int x;
	for(x = 0; x < MAX; x++){
		printf("%d ", catcher[x]);
	}
	
	return 0;
}
