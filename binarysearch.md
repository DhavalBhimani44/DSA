# Binary Search in C

This C code implements binary search, a searching algorithm that efficiently finds an element in a sorted array by repeatedly dividing the search interval in half.

## Implementation Details

The code provides two implementations of binary search:
1. **Iterative Binary Search:** The function `binarySearch` uses a loop to divide the array into smaller sub-arrays and compares the middle element with the target value.
2. **Recursive Binary Search:** The function `recbinarySearch` performs binary search recursively by dividing the array into sub-arrays and calling itself on the appropriate sub-array.

## Usage

1. Compile the code using a C compiler (e.g., GCC) by running the following command in the terminal:

    ```bash
    gcc binary_search.c -o binary_search
    ```

2. Run the compiled executable:

    ```bash
    ./binary_search
    ```

3. Follow the on-screen prompts to provide the size of the array, array elements, the element you want to search for, and your choice of search method.

4. The program will display whether the element was found and its index if found.

## Example

Suppose you want to search for the element 5 in a sorted array with elements [2, 4, 5, 7, 9, 12, 15]. After running the program and choosing the iterative binary search method, you should see:

```
Enter the size of the array: 7   
Enter the elements in the array:
2 4 5 7 9 12 15   
Enter the element you want to search: 5   

Choose the search method:           
1.Iterative Binary Search   
2.Recursive Binary Search

Enter your choice: 1   
Element found at index: 2
```