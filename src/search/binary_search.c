/*
Binary Search

This program implements the binary search algorithm, which is an efficient method for finding an item from a sorted list of items.

The binary search algorithm works by repeatedly dividing the search interval in half. 
If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. 
Otherwise, narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.

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
