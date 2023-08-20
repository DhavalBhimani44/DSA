# Bubble Sort in C

This C code demonstrates the Bubble Sort algorithm, a simple sorting technique that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process is repeated until no more swaps are needed, indicating that the list is sorted.

## Implementation Details

The code contains the following functions:

### `swap(int *x, int *y)`

This function takes two integer pointers `x` and `y` as arguments and swaps the values they point to. It's used to swap elements during the sorting process.

### `bubbleSort(int A[], int n)`

This function performs the Bubble Sort algorithm on an array `A` of size `n`. It compares adjacent elements and swaps them if they are in the wrong order. After each pass of the algorithm, the largest element "bubbles up" to its correct position at the end of the array. The process continues until the entire array is sorted.

## Usage

1. Compile the code using a C compiler (e.g., GCC) by running the following command in the terminal:

    ```bash
    gcc bubble_sort.c -o bubble_sort
    ```

2. Run the compiled executable:

    ```bash
    ./bubble_sort
    ```

3. Follow the on-screen prompts to provide the size of the array and the elements you want to sort.

4. The program will display the array after each pass of the bubble sort algorithm and the total number of passes.

## Example

Suppose you want to sort the elements [6, 3, 8, 5, 2] using the Bubble Sort algorithm. After running the program, you should see:

```
Enter the size of the array: 5
Enter the elements you want to sort: 6 3 8 5 2
After pass 1: 3 6 5 2 8
After pass 2: 3 5 2 6 8
After pass 3: 3 2 5 6 8
After pass 4: 2 3 5 6 8
Total no. of passes: 4

Elements after sorting:
2 3 5 6 8
```


# Explanation

Bubble Sort is a simple and intuitive sorting algorithm that repeatedly steps through the list to be sorted, compares adjacent elements, and swaps them if they are in the wrong order. It is a comparison-based algorithm that can be used for sorting arrays of any data type.

## Process

Bubble Sort operates as follows:

1. **Passes:** The algorithm consists of multiple passes through the array.

2. **Comparisons and Swaps:** In each pass, the algorithm compares adjacent elements from left to right. If the left element is greater than the right element (out of order), a swap is performed to put them in the correct order.

3. **Bubbling Up:** The largest element in the unsorted portion of the array "bubbles up" to its correct position in each pass.

4. **Repeat:** The process is repeated for the remaining elements until the entire array is sorted.

## Advantages

- **Simplicity:** Bubble Sort is easy to understand and implement, making it a good choice for educational purposes.

- **Adaptive:** If the array is nearly sorted, Bubble Sort's adaptive nature allows it to complete with fewer passes.

## Disadvantages

- **Inefficiency:** Bubble Sort is not efficient for large datasets due to its quadratic time complexity.

- **Performance:** It is slower compared to more advanced sorting algorithms, especially for larger arrays.

## Number of Passes and Swaps

- **Number of Passes:** Bubble Sort requires (n-1) passes for an array with n elements.

- **Number of Swaps:** Bubble Sort performs multiple swaps in each pass.

## Time Complexity

- Best Case: O(n) - when the array is already sorted.
- Average Case: O(n^2) - where n is the number of elements in the array.
- Worst Case: O(n^2) - when the array is reverse sorted.

## Usage

Bubble Sort is primarily used for educational purposes and small datasets. While not recommended for large-scale applications due to its inefficiency, it provides a clear understanding of how sorting algorithms work.

---

Note: The provided C code is for educational purposes and may not include extensive error handling or optimization. It serves as an example to demonstrate the concept of Bubble Sort in C programming.
