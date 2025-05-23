#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 0

typedef struct Vertex {
    int id;
    int d;      
    int pi;     
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
    }
    vertices[s].d = 0;
}

void Relax(Vertex vertices[], int u, int v, int w) {
    if (vertices[v].d > vertices[u].d + w && vertices[u].d != INT_MAX) {
        vertices[v].d = vertices[u].d + w;
        vertices[v].pi = u;
    }
}

int BellmanFord(Graph* graph, int s) {
    int V = graph->V;
    int E = graph->E;
    Vertex vertices[V];

   
    for (int i = 0; i < V; i++) {
        vertices[i].id = i;
    }
    InitializeSingleSource(vertices, V, s);

   
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edges[j].u;
            int v = graph->edges[j].v;
            int w = graph->edges[j].w;
            Relax(vertices, u, v, w);
        }
    }

   
    for (int j = 0; j < E; j++) {
        int u = graph->edges[j].u;
        int v = graph->edges[j].v;
        int w = graph->edges[j].w;
        if (vertices[v].d > vertices[u].d + w && vertices[u].d != INT_MAX) {
            return 0; 
        }
    }

   
    printf("\nVertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        if (vertices[i].d == INT_MAX)
            printf("%d        INF\n", i);
        else
            printf("%d        %d\n", i, vertices[i].d);
    }

    return 1;
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

    if (BellmanFord(&graph, source))
        printf("\nNo negative weight cycle detected.\n");
    else
        printf("\nNegative weight cycle detected.\n");
    for (int i = 0; i < V; i++) {
        free(adjMat[i]);
    }
    free(adjMat);
    free(graph.edges);

    return 0;
}
