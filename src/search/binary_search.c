/*
Binary Search

Guessing numbers from 1 to 10000.

*/
#include <stdio.h>

int binary_search(int low, int high, int target) {
    int guesses = 0;
    while (low <= high) {
        guesses++;
        int mid = (low + high) / 2;
        if (mid == target)
            break;
        else if (mid < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return guesses;
}

int main() {
    int target = 8192000;  // Given number to guess

    // Binary Search
    int binary_guesses = binary_search(1, 10000000, target);
    printf("Binary search found the number %d in %d guesses.\n", target, binary_guesses);

    return 0;
}
