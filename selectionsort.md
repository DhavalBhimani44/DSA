# Selection Sort in C

This C code demonstrates the Selection Sort algorithm, a simple sorting technique that repeatedly selects the minimum (or maximum) element from the unsorted portion of the array and swaps it with the leftmost unsorted element.

## Implementation Details

The code contains the following functions:

### `swap(int *x, int *y)`

This function takes two integer pointers `x` and `y` as arguments and swaps the values they point to. It's used to swap elements during the sorting process.

### `selectionSort(int A[], int n)`

This function performs the Selection Sort algorithm on an array `A` of size `n`. It finds the smallest element in the unsorted portion and swaps it with the leftmost unsorted element. This process is repeated until the entire array is sorted.

## Usage

1. Compile the code using a C compiler (e.g., GCC) by running the following command in the terminal:

    ```bash
    gcc selection_sort.c -o selection_sort
    ```

2. Run the compiled executable:

    ```bash
    ./selection_sort
    ```

3. Follow the on-screen prompts to provide the size of the array and the elements you want to sort.

4. The program will display the array after each pass of the selection sort algorithm and the total number of passes.

## Example

Suppose you want to sort the elements [6, 2, 8, 3, 1] using the Selection Sort algorithm. After running the program, you should see:

```
Enter the size of the array: 5
Enter the elements you want to sort: 6 2 8 3 1
After pass 1: 1 2 8 3 6
After pass 2: 1 2 8 3 6
After pass 3: 1 2 3 8 6
After pass 4: 1 2 3 6 8
Total no. of passes: 4

Elements after sorting:
1 2 3 6 8
```


# Explanation

Selection Sort is a simple sorting algorithm that repeatedly selects the smallest (or largest) element from the unsorted portion of the array and swaps it with the leftmost unsorted element. While not the most efficient sorting algorithm, Selection Sort is straightforward to implement and can be useful for small datasets or arrays with minimal memory writes.

## Process

1. **Passes:** Selection Sort consists of multiple passes through the array.

2. **Minimum Element:** In each pass, the smallest element from the unsorted portion is selected.

3. **Swap:** The selected element is swapped with the leftmost unsorted element.

4. **Repeat:** The process continues until the entire array is sorted.

## Advantages

- **Simple and Understandable:** Selection Sort is easy to understand and implement, making it a good choice for educational purposes.

- **Suitable for Small Datasets:** Selection Sort's simplicity makes it suitable for small datasets or arrays with minimal memory writes.

## Disadvantages

- **Inefficient for Large Datasets:** Selection Sort's time complexity is O(n^2), making it inefficient for large datasets.

- **Not Adaptive:** Unlike some other sorting algorithms, Selection Sort's performance doesn't improve based on the existing order of elements.

## Number of Passes and Swaps

- **Number of Passes:** Selection Sort requires n-1 passes for an array with n elements.

- **Number of Swaps:** Selection Sort performs (n-1) swaps in the worst case.

## Time Complexity

Selection Sort's time complexity is as follows:
- Best Case: O(n^2)
- Average Case: O(n^2)
- Worst Case: O(n^2)

## Conclusion

Selection Sort is a simple sorting algorithm that can be useful for small datasets or arrays with minimal memory writes. However, its inefficiency for larger datasets makes it less suitable for those scenarios. It's not adaptive, and there are other sorting algorithms like Quick Sort and Merge Sort that offer better performance for larger datasets.

Feel free to explore and understand the provided C code to see Selection Sort in action.

---

Note: The provided C code is for educational purposes and may not include extensive error handling or optimization. It serves as an example to demonstrate the concept of Selection Sort in C programming.

