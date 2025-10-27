# CS3334 Project

## Problem Statement
In this individual project, it is required to explore at least three different methods to find out the most frequent duplicate element in a given list of numbers.

## Compilation
All of the programs can be compiled with the following command:
```bash
g++ -std=c++11 your_program.cpp
```
Optionally, for optimization, you may use:
```bash
g++ -std=c++11 -O2 your_program.cpp -o output_name
```
## Methods Used
### 1. Brute Force
The brute force approach counts the frequency of each element in the array by iterating through every element. The complexities are as follows:

- Counting Frequencies: O(n²) in both the worst and best cases.
- Finding Most Common Element: O(n).

Thus, the total time complexity for T test examples is O(T * n²). This method performs best when all numbers are the same (e.g., 1 1 1 1 1). However, in the worst case, with all unique elements, the complexity remains O(n²).

### 2. Hashing
This method uses an unordered map to count the frequency of elements:

- Insertion/Update in Hash Map: O(1) on average.
- Finding Most Frequent Element: O(n).

The overall complexity is O(n) for T examples in the average/best case scenario. However, for large inputs where elements are multiples of 107897 or 126271, collisions may occur, leading to a worst-case complexity of O(n²).

### 3. AVL Tree
Using an AVL tree, we check for the existence of an integer and update its count while maintaining balance:

- Insertion and Retrieval: O(log n).

Thus, the complexity for processing an input line is O(n log n), even in the worst case of repeated digits, due to the logarithmic height of the tree.

### 4. Conclusion

On average, the hashing method outperforms both brute force and AVL tree methods. However, in scenarios with many collisions, the AVL tree maintains an O(n log n) complexity, while hashing may degrade to O(n²). If code simplicity is prioritized over performance, the brute force method remains a viable option.