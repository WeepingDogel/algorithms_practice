/*
Linear Search

Guessing numbers from 1 to 10000.

*/

#include <stdio.h>

int linear_search(int low, int high, int target) {
    int guesses = 0;
    for (int i = low; i <= high; i++) {
        guesses++;
        if (i == target)
            break;
    }
    return guesses;
}

int main() {
    int target = 8192000;  // Given number to guess

    // Linear Search
    int linear_guesses = linear_search(1, 10000000, target);
    printf("Linear search found the number %d in %d guesses.\n", target, linear_guesses);

    return 0;
}
