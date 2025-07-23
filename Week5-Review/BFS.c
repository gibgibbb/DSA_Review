#include <stdio.h>
#define SENTINEL -1
#define GRAPH_SIZE 8
#define TREE_SIZE 0xA

typedef int vertex;
typedef vertex Graph[GRAPH_SIZE][GRAPH_SIZE];

typedef unsigned char markType;

typedef struct {
	vertex tail, head;
}TreeArc;

typedef struct {
	TreeArc arcs[TREE_SIZE];
	int count;
}Tree;

Tree bfs(Graph G, vertex start){
	Queue Q;
	markType mark;
	Tree T;
	vertext x, y;
	
	initQueue(&Q);
	mark = 0;
	T.count = 0;
	
	mark|(1<<start);
	enqueue(&Q, start);
	while(front(Q) != SENTINEL){
		x = front(Q);
		dequeue(&Q);
		for(y = 0; y < GRAPH_SIZE; y++){
			if(G[x][y] != 0){
				if((mark&1<<y) == 0){
					mark = mark|(1<<y);
					enqueue(&Q, y);
					Tree Arc = {x,y};
					T.arcs[T.count++]=arc;
				}
			}
		}
	}
}
