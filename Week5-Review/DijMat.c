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
void FloydWarshall(AdjMat *C, AdjMat M);
void FloydWarshall2(AdjMat C, AdjMat M);

void FloydWarshall2(AdjMat C, AdjMat M){
    int i, j, k;

    /* 1) copy M ? C */
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            C[i][j] = M[i][j];
        }
    }

    /* 2) zero out the diagonal */
    for (i = 0; i < MAX; i++) {
        C[i][i] = 0;
    }

    /* 3) core FW relaxation */
    for (k = 0; k < MAX; k++) {
        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {
                /* only relax if both pieces are reachable */
                if (C[i][k] < INF && C[k][j] < INF &&
                    C[i][k] + C[k][j] < C[i][j]) {
                    C[i][j] = C[i][k] + C[k][j];
                }
            }
        }
    }
}

void FloydWarshall(AdjMat *C, AdjMat M) {
/* 2nd Version the pointer */
	int a, b, c;
	for(a = 0; a < MAX; a++){
		for(b = 0; b < MAX; b++){
			if(a != b){
				(*C)[a][b] = (M[a][b] != SENTINEL) ? M[a][b] : INF;
			} else {
				(*C)[a][b] = 0;
			}
		}
	}
	for(a = 0; a < MAX; a++){
		for(b = 0; b < MAX; b++){
			for(c = 0; c < MAX; c++){
				if((*C)[a][c] != INF && (*C)[c][b] != INF && (*C)[a][c] + (*C)[c][b] < (*C)[a][b]){
					(*C)[a][b] = (*C)[a][c] + (*C)[c][b];
				}
			}
		}
	}
}


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
	printf("Dij\n");
	for(x = 0; x < MAX; x++){
		printf("%d ", catcher[x]);
	}
	
	printf("\nFloydWarshall\n");
	AdjMat C;
    /* run Floyd–Warshall */
    FloydWarshall(&C, A);
//    FloydWarshall2(C, A);
    int i;
    for (i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (C[i][j] >= INF)
                printf(" INF");
            else
                printf("%4d", C[i][j]);
        }
        putchar('\n');
    }
	
	return 0;
}
