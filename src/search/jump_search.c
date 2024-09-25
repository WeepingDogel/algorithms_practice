#include <stdio.h>
#include <math.h>

// Function to perform jump search
int jump_search(int arr[], int n, int target) {
    int step = sqrt(n); // Calculate the optimal step size
    int prev = 0;

    // Jump ahead by the step size until the target element is found or the end of the array is reached
    while (arr[step - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1; // Target element is not present in the array
        }
    }

    // Perform a linear search in the last block
    for (int i = prev; i < step; i++) {
        if (arr[i] == target) {
            return i; // Target element found
        }
    }

    return -1; // Target element is not present in the array
}