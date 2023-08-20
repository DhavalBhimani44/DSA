#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr, int size, int key){
    int mid, l=0, h=size-1;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(key==arr[mid]){
            return mid;
        }
        else if (key<arr[mid])
        {
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}
int recbinarySearch(int *arr, int l, int h, int key){
    int mid;
    if(l<=h)
    {
        mid = (l+(h-1))/2;
        if(key==arr[mid]){
            return mid;
        }
        else if (key<arr[mid])
        {
            return recbinarySearch(arr, l, mid-1, key);
        }
        else{
            return recbinarySearch(arr, mid+1, h, key);
        }
    }
    return -1;
}

int main() {
    int size, key, choice;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter the elements in the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element you want to search: ");
    scanf("%d", &key);

    printf("Choose the search method:\n");
    printf("1. Iterative Binary Search\n");
    printf("2. Recursive Binary Search\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int result = -1;

    switch (choice) {
        case 1:
            result = binarySearch(arr, size, key);
            break;
        case 2:
            result = recbinarySearch(arr, 0, size - 1, key);
            break;
        default:
            printf("Invalid choice.\n");
            free(arr);
            return 1;
    }

    free(arr);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}