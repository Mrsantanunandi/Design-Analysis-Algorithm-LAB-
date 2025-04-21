#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct edge {
    int source;
    int destination;
    int weight;
} Edge;

typedef struct subset {
    int parent;
    int rank;
} Subset;

int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void kruskalsMST(Edge edges[], int V, int E) {
    Edge* result = (Edge*)malloc((V - 1) * sizeof(Edge));
    int e = 0, i = 0, sum = 0;

    qsort(edges, E, sizeof(Edge), compareEdges);

    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < E) {
        Edge nextEdge = edges[i++];
        int x = find(subsets, nextEdge.source);
        int y = find(subsets, nextEdge.destination);

        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    printf("\nEdge\tWeight\n");
    for (i = 0; i < e; ++i) {
        printf("%d -- %d\t%d\n", result[i].source + 1, result[i].destination + 1, result[i].weight);
        sum += result[i].weight;
    }

    printf("\nMinimum Spanning Tree cost is: %d\n", sum);

    free(subsets);
    free(result);
}

int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Allocate and read adjacency matrix
    int** adjmat = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        adjmat[i] = (int*)malloc(V * sizeof(int));
    }

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adjmat[i][j]);
        }
    }

    // Convert adjacency matrix to edge list
    int E = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (adjmat[i][j] != 0) {
                E++;
            }
        }
    }

    Edge* edges = (Edge*)malloc(E * sizeof(Edge));
    int index = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (adjmat[i][j] != 0) {
                edges[index].source = i;
                edges[index].destination = j;
                edges[index].weight = adjmat[i][j];
                index++;
            }
        }
    }

    clock_t start = clock();
    kruskalsMST(edges, V, E);
    clock_t end = clock();

    double cpu_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nCPU TIME: %lf SEC\n", cpu_time);

    // Free memory
    for (int i = 0; i < V; i++) {
        free(adjmat[i]);
    }
    free(adjmat);
    free(edges);

    return 0;
}

