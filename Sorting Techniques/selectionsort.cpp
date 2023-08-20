#include <stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int A[], int n){
    int i,j,k, passes=0;
    for(i=0; i<n-1; i++){
        for(j=k=i; j<n; j++){
            if(A[j]<A[k]){
                k=j;
            }
        }
        swap(&A[i], &A[k]);
        passes++;
        printf("After pass %d: ", passes);
        for (int k = 0; k < n; k++) {
            printf("%d ", A[k]);
        }
        printf("\n");
    }
        printf("Total no of passes: %d", passes);
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

    selectionSort(A, n);

    printf("\nElements after sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}