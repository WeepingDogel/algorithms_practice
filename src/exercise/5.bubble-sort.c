#include <stdio.h>

/*
Exercise 5: Bubble Sort
description:
    Implement bubble sort algorithm

Tips:
    "int" is a data type that represents an integer.
    "sizeof" is used to get the size of a variable or a type in bytes.
*/

/*TODO: Implement bubble sort algorithm*/
void bubbleSort(int arr[], int n) {
    /*TODO*/
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    bubbleSort(arr, n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
