#include <stdio.h>
#include <stdlib.h>
#include "graph_utils.h"

// Queue structure for BFS
typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->rear == -1;
}

// Function to enqueue an element
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Function to dequeue an element
int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// Function to perform BFS on the graph
void BFS(int startVertex, int numVertices) {
    Queue q;
    initQueue(&q);

    // Mark the start vertex as visited and enqueue it
    visited[startVertex] = 1;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        // Dequeue a vertex from the queue
        int currentVertex = dequeue(&q);
        printf("Visited %d\n", currentVertex);

        // Explore each adjacent vertex that has not been visited
        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
}
