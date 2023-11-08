# Insertion Sort

The program has four steps:

1. Read the size of an integer array, followed by the elements of the array (no duplicates).
2. Output the array.
3. Perform an insertion sort on the array.
4. Output the number of comparisons and swaps performed.

**main()** performs steps 1 and 2.

Implement step 3 based on the insertion sort algorithm in the book. Modify **InsertionSort()** to:

Count the number of comparisons performed.
Count the number of swaps performed.
Output the array during each iteration of the outside loop.
Complete **main()** to perform step 4, according to the format shown in the example below.

Hints: In order to count comparisons and swaps, modify the while loop in **InsertionSort()**. Use global variables for comparisons and swaps.

The program provides three helper functions:

```
// Read size numbers from cin into a new array and return the array.
int* ReadNums(int size)

// Print the numbers in the array, separated by spaces
// (No space or newline before the first number or after the last.)
void PrintNums(int nums[], int size)

// Exchange nums[j] and nums[k].
void Swap(int nums[], int j, int k)
```

Ex: When the input is:

```
6 3 2 1 5 9 8
```

the output is:

```
 3 2 1 5 9 8

 2 3 1 5 9 8
 1 2 3 5 9 8
 1 2 3 5 9 8
 1 2 3 5 9 8
 1 2 3 5 8 9

comparisons: 7
swaps: 4
```
