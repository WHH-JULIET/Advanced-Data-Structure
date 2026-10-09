#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

 struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Create and initialize graph with 0s
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Add an undirected edge
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // Omit for directed graphs
}

// Display the Adjacency Matrix
void printMatrix(Graph* graph) {
    printf("\nAdjacency Matrix (%d x %d):\n", graph->numVertices, graph->numVertices);
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// ==========================================
// Breadth-First Search (BFS) using Queue
// ==========================================
void BFS(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = { false };
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // 1. Initialize & Enqueue start vertex
    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("\nBFS Traversal starting from vertex %d: ", startVertex);

    // 2. Loop until Queue becomes empty
    while (front < rear) {
        int currentVertex = queue[front++]; // Dequeue
        printf("%d ", currentVertex);

        // Check all adjacent vertices
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i; // Enqueue
            }
        }
    }
    printf("\n");
}

// ==========================================
// Depth-First Search (DFS) using Stack
// ==========================================
void DFS(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = { false };
    int stack[MAX_VERTICES];
    int top = -1;

    // 1. Push start vertex onto stack
    stack[++top] = startVertex;

    printf("\nDFS Traversal starting from vertex %d: ", startVertex);

    // 2. Loop until Stack becomes empty
    while (top != -1) {
        int currentVertex = stack[top--]; // Pop top vertex

        if (!visited[currentVertex]) {
            visited[currentVertex] = true;
            printf("%d ", currentVertex);
        }

        // Push all unvisited adjacent vertices
        // Iterating in reverse to visit lower indices first
        for (int i = graph->numVertices - 1; i >= 0; i--) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                stack[++top] = i;
            }
        }
    }
    printf("\n");
}

// ==========================================
// Main Function
// ==========================================
int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    // Adding edges (Graph Vertices 0 to 4)
    addEdge(graph, 0, 1); // Edge 0-1
    addEdge(graph, 0, 2); // Edge 0-2
    addEdge(graph, 1, 3); // Edge 1-3
    addEdge(graph, 1, 4); // Edge 1-4
    addEdge(graph, 2, 4); // Edge 2-4

    printMatrix(graph);

    // Run Traversals starting from Vertex 0
    BFS(graph, 0);
    DFS(graph, 0);

    return 0;
}
