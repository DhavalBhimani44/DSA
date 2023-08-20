# Linear Search in C

This C code implements linear search, a simple searching algorithm that searches for an element in an array by iterating through each element and comparing it with the target value.

## Implementation Details

The code provides two implementations of linear search:
1. **Iterative Linear Search:** The function `linearSearch` iterates through the array and returns the index of the element if found, otherwise returns -1.
2. **Recursive Linear Search:** The function `reclinearSearch` performs the linear search recursively by checking each element in the array, similar to the iterative version.

## Usage

1. Compile the code using a C compiler (e.g., GCC) by running the following command in the terminal:

    ```bash
    gcc linear_search.c -o linear_search
    ```

2. Run the compiled executable:

    ```bash
    ./linear_search
    ```

3. Follow the on-screen prompts to provide the size of the array, array elements, and the element you want to search for.

4. The program will display whether the element was found and its index if found.

## Example

Suppose you want to search for the element 5 in an array with elements [1, 3, 5, 7, 8]. After running the program, you should see:

```
Enter the size of the array: 5   
Enter the elements in the array:   
1 3 5 7 8   
Enter the element you want to search: 5   
Element found at 2
```