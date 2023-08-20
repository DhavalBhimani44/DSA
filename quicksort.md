# Quick Sort in C

This C code demonstrates the Quick Sort algorithm, a widely used sorting technique that employs a divide-and-conquer strategy. Quick Sort works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot.

## Implementation Details

The code contains the following functions:

### `swap(int *x, int *y)`

This function takes two integer pointers `x` and `y` as arguments and swaps the values they point to. It's used to swap elements during the sorting process.

### `partition(int A[], int l, int h)`

This function partitions the array `A` into two sub-arrays using a pivot element. It rearranges elements so that elements smaller than the pivot are on the left, and elements greater than the pivot are on the right. The function returns the index of the pivot after partitioning.

### `quicksort(int A[], int l, int h)`

This function recursively sorts the array `A` using the Quick Sort algorithm. It selects a pivot, partitions the array, and then recursively sorts the left and right sub-arrays.

## Usage

1. Compile the code using a C compiler (e.g., GCC) by running the following command in the terminal:

    ```bash
    gcc quick_sort.c -o quick_sort
    ```

2. Run the compiled executable:

    ```bash
    ./quick_sort
    ```

3. Follow the on-screen prompts to provide the size of the array and the elements you want to sort.

4. The program will display the pivot selected at each partition step and the elements after each partition.

## Example

Suppose you want to sort the elements [9, 2, 7, 5, 1] using the Quick Sort algorithm. After running the program, you should see:

```
Enter the size of the array: 5
Enter the elements in the array: 9 2 7 5 1
pivot: 1
pass: [1] 2 7 5 9
pivot: 2
pass: 1 [2] 7 5 9
pivot: 5
pass: 1 2 [5] 7 9
pivot: 7
pass: 1 2 5 [7] 9
After sorting:
1 2 5 7 9
```



# Explanation

Quicksort is a widely-used efficient sorting algorithm based on the divide-and-conquer strategy. It works by selecting a pivot element and partitioning the array into sub-arrays such that elements smaller than the pivot are on its left and elements larger are on its right. Quicksort's efficient average-case time complexity makes it a popular choice for sorting large datasets.

## Divide and Conquer Strategy

Quicksort's effectiveness is due to its divide-and-conquer approach:

1. **Pivot Selection:** A pivot element is chosen from the array. The choice of pivot affects the performance of the algorithm.

2. **Partitioning:** The array is partitioned into sub-arrays, with elements less than the pivot on the left and elements greater on the right.

3. **Recursion:** Quicksort is applied recursively to the left and right sub-arrays.

## Sorting Process

Here's how Quicksort works step by step:

1. **Pivot Selection:** A pivot element is chosen, often as the first or last element of the array.

2. **Partitioning:** The array is rearranged so that elements less than the pivot are on its left and elements greater are on its right. The pivot is now in its final sorted position.

3. **Recursion:** Quicksort is applied recursively to the left and right sub-arrays, repeating the partitioning process.

## Advantages

- **Efficient Average Case:** Quicksort's average-case time complexity is O(n log n), making it efficient for sorting large datasets.

- **Adaptive:** Quicksort's performance improves when the array is partially sorted.

- **In-place Sorting:** Quicksort can be implemented with low memory overhead as it doesn't require additional memory for merging or partitioning.

## Disadvantages

- **Worst Case:** Quicksort's worst-case time complexity is O(n^2), which occurs when the pivot choice consistently results in unbalanced partitions.

## Number of Passes and Swaps

- **Number of Passes:** Quicksort requires log₂(n) passes for an array with n elements.

- **Number of Swaps:** The number of swaps varies depending on the choice of pivot and the distribution of elements.

## Time Complexity

Quicksort's time complexity varies based on the choice of pivot and the distribution of elements:
- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n^2)

## Conclusion

Quicksort is an efficient sorting algorithm with a balanced partitioning strategy, making it highly suitable for sorting large datasets. Its adaptive nature and low memory usage contribute to its popularity. However, careful pivot selection is essential to avoid worst-case scenarios.

Feel free to explore the provided C code to see Quicksort in action.

---

Note: The provided C code is for educational purposes and may not include extensive error handling or optimization. It serves as an example to demonstrate the concept of Quicksort in C programming.

