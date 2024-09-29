/*
 * This program implements the insertion sort algorithm, which is a simple and intuitive sorting technique.
 *
 * The insertion sort algorithm works by building a sorted portion of the array one element at a time.
 * It iterates through the array, and for each element, it compares it with the elements in the sorted portion
 * (to its left) and inserts it into the correct position. The process can be visualized as sorting a hand of playing cards:
 * you take one card at a time and insert it into its correct position among the already sorted cards.
 *
 * The main components of the code are as follows:
 *
 * 1. **Function `insertionSort(int arr[], int n)`**:
 *    - This function takes an array `arr` and its size `n` as parameters.
 *    - It starts from the second element (index 1) and iterates through the array.
 *    - For each element (referred to as `key`), it compares it with the elements in the sorted portion of the array.
 *    - It uses a nested loop to shift elements that are greater than `key` one position to the right, making space for `key`.
 *    - Once the correct position is found, `key` is placed in that position.
 *
 * 2. **Function `printArray(int arr[], int n)`**:
 *    - This function prints the elements of the array.
 *    - It iterates through the array and prints each element followed by a space.
 *
 * 3. **Function `main()`**:
 *    - This is the entry point of the program.
 *    - It initializes an array of unsorted integers.
 *    - It calculates the size of the array using `sizeof`.
 *    - It prints the original unsorted array.
 *    - It calls the `insertionSort` function to sort the array.
 *    - Finally, it prints the sorted array.
 *
 * The time complexity of the insertion sort algorithm is O(n^2) in the average and worst cases, making it inefficient for large datasets.
 * However, it performs well for small datasets or nearly sorted arrays, where its time complexity can approach O(n).
 */

#include <stdio.h>
#include "sort_utils.h"

// Function to perform insertion sort on an array
void insertionSort(int arr[], int n)
{
    int i, key, j;
    // Start from the second element (index 1)
    for (i = 1; i < n; i++)
    {
        // Store the current element as key
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Place the key in its correct position
        arr[j + 1] = key;
    }
}
