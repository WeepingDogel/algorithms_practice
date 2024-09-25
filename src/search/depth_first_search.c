#include <stdio.h>
#include <stdlib.h>
#include "graph_utils.h"

// Function to perform DFS on the graph
void DFS(int vertex, int numVertices) {
    // Mark the current vertex as visited
    visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    // Explore each adjacent vertex that has not been visited
    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i, numVertices);
        }
    }
}
