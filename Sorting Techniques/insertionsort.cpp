#include <stdio.h>

void insertionSort(int A[], int n){
    int i,j,x;
    for ( i = 1; i < n; i++)
    {
        j = i-1;
        x = A[i];
        while (j>-1 && A[j]>x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1]=x;

        printf("Pass:%d = ", i);
        for (int i = 0; i < n; i++) 
        {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
}

int main(){
    int n,i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter the elements you want to sort: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    insertionSort(A, n);

    printf("\nElements after sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}