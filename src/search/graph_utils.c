#include "graph_utils.h"

// Adjacency matrix to represent the graph
int adjMatrix[MAX_VERTICES][MAX_VERTICES];

// Array to keep track of visited vertices
int visited[MAX_VERTICES];

// Function to add an edge to the graph
void addEdge(int start, int end) {
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1; // For undirected graph
}