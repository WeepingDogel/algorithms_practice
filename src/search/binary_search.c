/*
Binary Search

This program implements the binary search algorithm, which is an efficient method for finding an item from a sorted list of items.

The binary search algorithm works by repeatedly dividing the search interval in half. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. Otherwise, narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.

The main components of the code are as follows:

1. **Function `binary_search(int low, int high, int target)`**:
   - This function takes the lower bound `low`, upper bound `high`, and the `target` value to search for.
   - It initializes a counter `guesses` to keep track of the number of guesses made.
   - It enters a loop that continues as long as `low` is less than or equal to `high`.
   - In each iteration, it calculates the middle index `mid` and compares the value at `mid` with the `target`.
   - If the value at `mid` is equal to the `target`, it breaks out of the loop.
   - If the value at `mid` is less than the `target`, it updates `low` to `mid + 1`.
   - If the value at `mid` is greater than the `target`, it updates `high` to `mid - 1`.
   - It returns the number of guesses made.

2. **Function `main()`**:
   - This is the entry point of the program.
   - It initializes a `target` value to search for.
   - It calls the `binary_search` function with the range from 1 to 10,000,000 and the `target` value.
   - It prints the number of guesses made by the binary search algorithm.

The time complexity of the binary search algorithm is O(log n), making it very efficient for large datasets.
*/

#include <stdio.h>

// Function to perform binary search
int binary_search(int low, int high, int target) {
    int guesses = 0; // Initialize the number of guesses
    while (low <= high) {
        guesses++; // Increment the number of guesses
        int mid = (low + high) / 2; // Calculate the middle index
        if (mid == target) // If the middle element is the target
            break; // Exit the loop
        else if (mid < target) // If the middle element is less than the target
            low = mid + 1; // Narrow the search to the upper half
        else // If the middle element is greater than the target
            high = mid - 1; // Narrow the search to the lower half
    }
    return guesses; // Return the number of guesses made
}

int main() {
    int target = 8192000; // Given number to guess

    // Binary Search
    int binary_guesses = binary_search(1, 10000000, target);
    printf("Binary search found the number %d in %d guesses.\n", target, binary_guesses);

    return 0;
}
