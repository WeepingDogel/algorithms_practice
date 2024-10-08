#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph_utils.h"

// Function declarations for search algorithms
int linear_search(int low, int high, int target);
int binary_search(int low, int high, int target);
int jump_search(int arr[], int n, int target);
void DFS(int vertex, int numVertices);
void BFS(int startVertex, int numVertices);

// Function to generate a sorted array with sequential values
void generateSortedArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1; // Fill the array with sequential values starting from 1
    }
}

// Function to measure the time taken by a search algorithm
void measureTime(int (*searchFunc)(int, int, int), int arr[], int size, int target, const char* searchName) {
    // Record the start time
    clock_t start = clock();
    
    // Call the search function and get the number of guesses
    int guesses = searchFunc(1, size, target);
    
    // Record the end time
    clock_t end = clock();

    // Calculate the time taken in seconds
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Print the results
    printf("%s took %f seconds and %d guesses to find the target %d in an array of size %d.\n", searchName, timeTaken, guesses, target, size);
}

// Function to measure the time taken by Jump Search
void measureJumpSearchTime(int (*searchFunc)(int[], int, int), int arr[], int size, int target, const char* searchName) {
    // Record the start time
    clock_t start = clock();
    
    // Call the search function and get the index
    int index = searchFunc(arr, size, target);
    
    // Record the end time
    clock_t end = clock();

    // Calculate the time taken in seconds
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Print the results
    printf("%s took %f seconds to find the target %d at index %d in an array of size %d.\n", searchName, timeTaken, target, index, size);
}

// Function to measure the time taken by DFS and BFS
void measureGraphSearchTime(void (*searchFunc)(int, int), int numVertices, const char* searchName) {
    // Record the start time
    clock_t start = clock();
    
    // Call the search function
    searchFunc(0, numVertices);
    
    // Record the end time
    clock_t end = clock();

    // Calculate the time taken in seconds
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Print the results
    printf("%s took %f seconds to traverse the graph with %d vertices.\n", searchName, timeTaken, numVertices);
}

// Main function to test the search algorithms
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Array of different sizes to test
    int sizes[] = {1000, 5000, 10000, 50000, 100000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    // Loop through each size
    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        
        // Allocate memory for the array
        int* arr = (int*)malloc(size * sizeof(int));
        
        // Generate a sorted array with sequential values
        generateSortedArray(arr, size);

        // Generate a random target within the array
        int target = rand() % size + 1;

        printf("Testing with array size: %d\n", size);

        // Measure the time taken by Linear Search
        measureTime(linear_search, arr, size, target, "Linear Search");
        
        // Measure the time taken by Binary Search
        measureTime(binary_search, arr, size, target, "Binary Search");

        // Measure the time taken by Jump Search
        measureJumpSearchTime(jump_search, arr, size, target, "Jump Search");

        // Free the allocated memory
        free(arr);
        printf("\n");
    }

    // Graph search tests
    int numVertices = 6;

    // Initialize the adjacency matrix and visited array
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Add edges to the graph
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);

    // Measure the time taken by DFS
    measureGraphSearchTime(DFS, numVertices, "Depth-First Search (DFS)");

    // Reset the visited array
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    // Measure the time taken by BFS
    measureGraphSearchTime(BFS, numVertices, "Breadth-First Search (BFS)");

    return 0;
}