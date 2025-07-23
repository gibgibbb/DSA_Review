#define MAX 10
#define infinity 999
#include <stdio.h>
#include <stdlib.h>

typedef enum{TRUE, FALSE
}Boolean;
typedef int LabelAdjMat[MAX][MAX];
typedef struct {
    int u, w;
    int weight;
}edgeType;

typedef struct node {
    edgeType N;
    struct node* next;
}*edgeList;

typedef struct {
    edgeList L;
    int cost; //total cost of the weight
}MstKruskal;

edgeList createEdgeList(LabelAdjMat M){
    int x, y;
    edgeList List = NULL, *trav, temp;
    for(x = 1; x < MAX; x++){
        for(y = 0; y < x; y++){
            if(M[x][y] != infinity){
                temp = (edgeList)malloc(sizeof(struct node));
                temp->N.u = x;
                temp->N.w = y;
                temp->N.weight = M[x][y];
                for(trav = &List; *trav != NULL && (*trav)->N.weight < temp->N.weight; trav = &(*trav)->next){}
                temp->next = *trav;
                *trav = temp;
            }
        }
    }
    return List;
}

MstKruskal createMstPrims(LabelAdjMat M) {
    MstKruskal MST;
    Boolean visited[MAX] = { FALSE };
    int parent[MAX];
    int key[MAX];
    int i;

    /* initialize */
    for (i = 0; i < MAX; i++) {
        key[i]     = infinity;
        parent[i]  = -1;
        visited[i] = FALSE;
    }
    /* start from vertex 0 */
    key[0] = 0;

    /* repeated MAX-1 times */
    for (int count = 0; count < MAX - 1; count++) {
        /* pick the unvisited vertex u with smallest key[u] */
        int u = -1, min = infinity;
        for (i = 0; i < MAX; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u   = i;
            }
        }
        if (u < 0) break;           /* no more reachable vertices */
        visited[u] = TRUE;

        /* relax edges u?v */
        for (int v = 0; v < MAX; v++) {
            if (!visited[v]
                && M[u][v] != infinity
                && M[u][v] < key[v])
            {
                key[v]    = M[u][v];
                parent[v] = u;
            }
        }
    }

    /* build the edge-list from parent[] and compute total cost */
    MST.L    = NULL;
    MST.cost = 0;
    for (i = 1; i < MAX; i++) {
        if (parent[i] != -1) {
            edgeList node = malloc(sizeof *node);
            node->N.u      = i;
            node->N.w      = parent[i];
            node->N.weight = M[i][parent[i]];
            node->next     = MST.L;
            MST.L          = node;
            MST.cost     += node->N.weight;
        }
    }

    return MST;
}

MstKruskal createMstKruskal(LabelAdjMat M){
    MstKruskal MST;
    int parent[MAX], x, setU, setW, trav;
    edgeList temp;

    MST.L = NULL;
    MST.cost = 0;

    for(x = 0; x < MAX; x++){
        parent[x] = x;
    }

    edgeList sortedEdges = createEdgeList(M);

    for(temp = sortedEdges; temp != NULL; temp = temp->next){
        trav = temp->N.u;
        for(;parent[trav] != trav; trav = parent[trav]){}
        setU = trav;
        trav = temp->N.w;
        for(;parent[trav] != trav; trav = parent[trav]){}
        setW = trav;

        if(setU != setW){
            parent[setU] = setW;
            edgeList edge = (edgeList)malloc(sizeof(struct node));
            edge->N= temp->N;
            edge->next = MST.L;
            MST.L = edge;
        }
        MST.cost += temp->N.weight;
    }
    return MST;
}

int main() {
    LabelAdjMat graph;
    int i, j;
    MstKruskal result;

    // Initialize adjacency matrix
    for(i = 0; i < MAX; i++) {
        for(j = 0; j < MAX; j++) {
            graph[i][j] = infinity;
        }
    }

    graph[1][0] = graph[0][1] = 2;
    graph[2][0] = graph[0][2] = 4;
    graph[2][1] = graph[1][2] = 1;
    graph[3][1] = graph[1][3] = 3;
    graph[3][2] = graph[2][3] = 5;

    // Create MST using Kruskal's algorithm
    result = createMstKruskal(graph);

    // Print the edges in MST
    printf("Edges in Minimum Spanning Tree:\n");
    edgeList temp;
    for(temp = result.L; temp != NULL; temp = temp->next) {
        printf("Edge: %d - %d, Weight: %d\n",
               temp->N.u, temp->N.w, temp->N.weight);
    }

    // Print total cost
    printf("Total cost of MST: %d\n", result.cost);

//	MstKruskal primResult = createMstPrims(graph);
//
//    /* print Prim�s MST */
//    printf("Prims MST edges:\n");
//    for (edgeList e = primResult.L; e != NULL; e = e->next) {
//        printf("  %d � %d  (weight %d)\n",
//               e->N.u, e->N.w, e->N.weight);
//    }
//    printf("Total cost = %d\n", primResult.cost);

    return 0;
}


