#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF 0
typedef struct Vertex {
    int id;
    int d;
    int pi;
    int visited;
} Vertex;

typedef struct Edge {
    int u, v;
    int w;
} Edge;

typedef struct Graph {
    int V, E;
    Edge* edges;
} Graph;

void InitializeSingleSource(Vertex vertices[], int V, int s) {
    for (int i = 0; i < V; i++) {
        vertices[i].d = INT_MAX;
        vertices[i].pi = -1;
        vertices[i].visited = 0;
    }
    vertices[s].d = 0;
}

int ExtractMin(Vertex vertices[], int V) {
    int min = INT_MAX;
    int u = -1;
    for (int i = 0; i < V; i++) {
        if (!vertices[i].visited && vertices[i].d < min) {
            min = vertices[i].d;
            u = i;
        }
    }
    return u;
}

void Dijkstra(Graph* graph, int** adjMat, int s) {
    int V = graph->V;
    Vertex vertices[V];

    for (int i = 0; i < V; i++) {
        vertices[i].id = i;
    }
    InitializeSingleSource(vertices, V, s);

    for (int count = 0; count < V - 1; count++) {
        int u = ExtractMin(vertices, V);
        if (u == -1) {
            break;
        }
        vertices[u].visited = 1;
        for (int v = 0; v < V; v++) {
            if (!vertices[v].visited && adjMat[u][v] != INF && vertices[u].d != INT_MAX) {
                if (vertices[v].d > vertices[u].d + adjMat[u][v]) {
                    vertices[v].d = vertices[u].d + adjMat[u][v];
                    vertices[v].pi = u;
                }
            }
        }
    }

    printf("\nVertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        if (vertices[i].d == INT_MAX)
            printf("%d        INF\n", i);
        else
            printf("%d        %d\n", i, vertices[i].d);
    }
}



int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int** adjMat = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        adjMat[i] = (int*)malloc(V * sizeof(int));
    }

    printf("Enter the adjacency matrix (use %d for INF if no edge):\n", INF);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adjMat[i][j]);
        }
    }

    int edgeCount = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adjMat[i][j] != INF && i != j) {
                edgeCount++;
            }
        }
    }

    Graph graph;
    graph.V = V;
    graph.E = edgeCount;
    graph.edges = (Edge*)malloc(edgeCount * sizeof(Edge));

    int idx = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adjMat[i][j] != INF && i != j) {
                graph.edges[idx].u = i;
                graph.edges[idx].v = j;
                graph.edges[idx].w = adjMat[i][j];
                idx++;
            }
        }
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    Dijkstra(&graph, adjMat, source);

    for (int i = 0; i < V; i++) {
        free(adjMat[i]);
    }
    free(adjMat);
    free(graph.edges);

    return 0;
}
