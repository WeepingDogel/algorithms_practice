#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

#define MAX_VERTICES 100

// Adjacency matrix to represent the graph
extern int adjMatrix[MAX_VERTICES][MAX_VERTICES];

// Array to keep track of visited vertices
extern int visited[MAX_VERTICES];

// Function to add an edge to the graph
void addEdge(int start, int end);

#endif // GRAPH_UTILS_H