# Insertion Sort in C

This C code demonstrates the Insertion Sort algorithm, a simple sorting technique that builds the final sorted array one item at a time. It takes each element and inserts it into its correct position within the already sorted portion of the array.

## Implementation Details

The code contains the following functions:

### `insertionSort(int A[], int n)`

This function performs the Insertion Sort algorithm on an array `A` of size `n`. It iterates through the array, compares each element with the preceding elements in the sorted portion, and inserts the element at its correct position.

## Usage

1. Compile the code using a C compiler (e.g., GCC) by running the following command in the terminal:

    ```bash
    gcc insertion_sort.c -o insertion_sort
    ```

2. Run the compiled executable:

    ```bash
    ./insertion_sort
    ```

3. Follow the on-screen prompts to provide the size of the array and the elements you want to sort.

4. The program will display the array after each pass of the insertion sort algorithm.

## Example

Suppose you want to sort the elements [9, 4, 7, 2, 1] using the Insertion Sort algorithm. After running the program, you should see:

```
Enter the size of the array: 5
Enter the elements you want to sort: 9 4 7 2 1
Pass:1 = 4 9 7 2 1
Pass:2 = 4 7 9 2 1
Pass:3 = 2 4 7 9 1
Pass:4 = 1 2 4 7 9

Elements after sorting:
1 2 4 7 9
```


# Explanation

Insertion Sort is a simple and efficient sorting algorithm that builds a sorted array by iteratively inserting elements from the unsorted portion into their correct positions in the sorted portion. It is especially effective for small datasets or partially sorted arrays.

## Process

1. **Initial Division:** The array is divided into two portions: a sorted sub-array and an unsorted sub-array. The sorted sub-array initially contains only the first element.

2. **Insertion:** In each pass, an element from the unsorted sub-array is selected and inserted into its correct position in the sorted sub-array. The element is compared with the elements in the sorted sub-array and shifted to the right until its proper position is found.

3. **Shifting:** During insertion, elements greater than the selected element are shifted to the right to make space for the insertion.

4. **Repeat:** The process continues until the entire unsorted sub-array becomes empty, and all elements are sorted.

## Advantages

- **Adaptive:** Insertion Sort is adaptive, meaning its performance improves when the array is partially sorted. In this case, fewer comparisons and shifts are needed.

- **Efficient for Small Datasets:** Insertion Sort is efficient for small datasets or arrays that are nearly sorted.

## Disadvantages

- **Inefficient for Large Datasets:** Insertion Sort's time complexity is O(n^2), making it inefficient for large datasets.

## Number of Passes and Shifts

- **Number of Passes:** Insertion Sort requires (n-1) passes for an array with n elements.

- **Number of Shifts:** In the worst case, Insertion Sort performs several shifts in each pass.

## Time Complexity

Insertion Sort's time complexity is as follows:
- Best Case: O(n) (when the array is nearly sorted)
- Average Case: O(n^2)
- Worst Case: O(n^2)

## Conclusion

Insertion Sort is a simple yet efficient sorting algorithm that works well for small datasets or partially sorted arrays. Its adaptive nature makes it perform better when elements are already partially in order. However, it's not recommended for large datasets due to its higher time complexity.

Feel free to explore and understand the provided C code to see Insertion Sort in action.

---

Note: The provided C code is for educational purposes and may not include extensive error handling or optimization. It serves as an example to demonstrate the concept of Insertion Sort in C programming.
