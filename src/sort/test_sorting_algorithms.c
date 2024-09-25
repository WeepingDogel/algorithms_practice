#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort_utils.h"

// Function declarations for sorting algorithms
void quickSort(int arr[], int low, int high);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);

// Function to generate an array with random values
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // Random values between 0 and 9999
    }
}

// Function to copy an array
void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

// Function to measure the time taken by a sorting algorithm
void measureTime(void (*sortFunc)(int[], int, int), int arr[], int size, const char* sortName) {
    int* tempArr = (int*)malloc(size * sizeof(int));
    copyArray(arr, tempArr, size);

    clock_t start = clock();
    sortFunc(tempArr, 0, size - 1);
    clock_t end = clock();

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%s took %f seconds to sort %d elements.\n", sortName, timeTaken, size);

    free(tempArr);
}

// Wrapper function for insertion sort to match the signature
void insertionSortWrapper(int arr[], int low, int high) {
    insertionSort(arr, high + 1);
}

// Main function to test the sorting algorithms
int main() {
    srand(time(NULL));

    int sizes[] = {1000, 5000, 10000, 50000, 100000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        int* arr = (int*)malloc(size * sizeof(int));
        generateRandomArray(arr, size);

        printf("Testing with array size: %d\n", size);

        measureTime(quickSort, arr, size, "Quick Sort");
        measureTime(insertionSortWrapper, arr, size, "Insertion Sort");
        measureTime(mergeSort, arr, size, "Merge Sort");

        free(arr);
        printf("\n");
    }

    return 0;
}