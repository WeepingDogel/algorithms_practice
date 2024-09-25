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

