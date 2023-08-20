#include <stdio.h>

int linearSearch(int A[], int size, int key){
    int i, count=0;
    for (i = 0; i < size; i++)
    {
        if (key==A[i])      
        {
            return i;
        }
    }   
    return -1;
}

int reclinearSearch(int A[], int start, int end, int key){
    if(start>end)
    {
        return -1;
    }
    if (A[start]==key)
    {
        return start;
    }
    return reclinearSearch(A, start+1, end, key);
}

int main(){
    int arr[10];
    int size, key, i, result;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements in the array:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element you want to search: ");
    scanf("%d", &key);

    result = linearSearch(arr, size-1, key);

    if (result!=-1)
    {
        printf("Element found at %d", result);
    }else{
        printf("Element not found!");
    }

    return 0;
}