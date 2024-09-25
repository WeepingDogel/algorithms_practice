## Algorithms Experimental Codes

This repository is used to store my codes for learning data structures and algorithms.

### Project Structure

```
.
├── README.md
├── execution_duration_log.txt
├── src
│ ├── search
│ │ ├── binary_search.c
│ │ ├── linear_search.c
│ │ ├── jump_search.c
│ │ └── test_search_algorithms.c
│ ├── sort
│ │ ├── insertion_sort.c
│ │ ├── merge_sort.c
│ │ ├── quick_sort.c
│ │ ├── bubble_sort.c
│ │ ├── selection_sort.c
│ │ ├── sort_utils.c
│ │ ├── sort_utils.h
│ │ └── test_sorting_algorithms.c
│ └── test_time.py
└── .gitignore
```

### Sorting Algorithms

#### Quick Sort

**Description**: Quick Sort is a divide-and-conquer algorithm. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.

**Strengths**:
- Generally faster than other O(n log n) algorithms for large datasets.
- In-place sorting algorithm (requires only a small, constant amount of additional storage space).

**Weaknesses**:
- Worst-case time complexity is O(n^2), although this can be mitigated with good pivot selection strategies (e.g., using the median-of-three method).

**Time Complexity**:
- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n^2)

**Space Complexity**: O(log n) due to the recursion stack.

#### Insertion Sort

**Description**: Insertion Sort is a simple sorting algorithm that builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

**Strengths**:
- Simple to implement.
- Efficient for small datasets or nearly sorted arrays.
- In-place sorting algorithm.

**Weaknesses**:
- Inefficient for large datasets due to its O(n^2) time complexity.

**Time Complexity**:
- Best Case: O(n)
- Average Case: O(n^2)
- Worst Case: O(n^2)

**Space Complexity**: O(1)

#### Merge Sort

**Description**: Merge Sort is a divide-and-conquer algorithm that divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.

**Strengths**:
- Consistent O(n log n) time complexity.
- Stable sorting algorithm (maintains the relative order of equal elements).

**Weaknesses**:
- Requires additional space proportional to the size of the input array (O(n) space complexity).

**Time Complexity**:
- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n)

**Space Complexity**: O(n)

#### Bubble Sort

**Description**: Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

**Strengths**:
- Simple to implement.
- Can detect if the list is already sorted.

**Weaknesses**:
- Very inefficient for large datasets due to its O(n^2) time complexity.

**Time Complexity**:
- Best Case: O(n)
- Average Case: O(n^2)
- Worst Case: O(n^2)

**Space Complexity**: O(1)

#### Selection Sort

**Description**: Selection Sort is a simple sorting algorithm that divides the input list into two parts: the sublist of items already sorted, which is built up from left to right at the front (left) of the list, and the sublist of items remaining to be sorted that occupy the rest of the list.

**Strengths**:
- Simple to implement.
- Performs well on small datasets.

**Weaknesses**:
- Inefficient for large datasets due to its O(n^2) time complexity.
- Not stable (does not maintain the relative order of equal elements).

**Time Complexity**:
- Best Case: O(n^2)
- Average Case: O(n^2)
- Worst Case: O(n^2)

**Space Complexity**: O(1)

### Searching Algorithms

#### Linear Search

**Description**: Linear Search is a simple search algorithm that checks every element in the list until the target value is found or the list ends.

**Strengths**:
- Simple to implement.
- Does not require the list to be sorted.

**Weaknesses**:
- Inefficient for large datasets due to its O(n) time complexity.

**Time Complexity**:
- Best Case: O(1)
- Average Case: O(n)
- Worst Case: O(n)

**Space Complexity**: O(1)

#### Binary Search

**Description**: Binary Search is an efficient method for finding an item from a sorted list of items. It works by repeatedly dividing the search interval in half.

**Strengths**:
- Very efficient for large datasets with O(log n) time complexity.
- Simple to implement.

**Weaknesses**:
- Requires the list to be sorted.

**Time Complexity**:
- Best Case: O(1)
- Average Case: O(log n)
- Worst Case: O(log n)

**Space Complexity**: O(1)

#### Jump Search

**Description**: Jump Search is a searching algorithm for sorted arrays. The basic idea is to check fewer elements by jumping ahead by fixed steps or skipping some elements in place of searching all elements.

**Strengths**:
- More efficient than linear search for large datasets.
- Simple to implement.

**Weaknesses**:
- Requires the list to be sorted.
- Less efficient than binary search.

**Time Complexity**:
- Best Case: O(1)
- Average Case: O(√n)
- Worst Case: O(√n)

**Space Complexity**: O(1)

### How to Compile and Run

#### Sorting Algorithms

1. **Compile**

   ```bash
   gcc -o test_sorting_algorithms src/sort/test_sorting_algorithms.c src/sort/quick_sort.c src/sort/insertion_sort.c src/sort/merge_sort.c src/sort/bubble_sort.c src/sort/selection_sort.c src/sort/sort_utils.c
   ```

2. **Run**
   ```bash
   ./test_sorting_algorithms
   ```

#### Searching Algorithms

1. **Compile**

   ```bash
   gcc -o test_search_algorithms src/search/test_search_algorithms.c src/search/linear_search.c src/search/binary_search.c src/search/jump_search.c
   ```

2. **Run**
   ```bash
   ./test_search_algorithms
   ```

### Execution Duration Log

The `execution_duration_log.txt` file contains the logs of the execution duration for different algorithms. This can be useful for analyzing the performance of the algorithms.

### Python Script

The `src/test_time.py` script can be used to automate the testing of the execution time for the algorithms. This script compiles the C programs, runs them, and logs the execution duration.

### .gitignore

The `.gitignore` file is used to specify which files and directories should be ignored by Git. This typically includes compiled binaries, log files, and other temporary files.

### Future Work

- Implement additional sorting and searching algorithms.
- Add more detailed analysis and comparison of the algorithms.
- Implement the `test_time.py` script to automate performance testing.
