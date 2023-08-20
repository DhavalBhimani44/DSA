#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l, j = h;

    do {
        while (A[i] <= pivot) i++;
        while (A[j] > pivot) j--;

        if (i < j) swap(&A[i], &A[j]);
    } while (i < j);

    swap(&A[l], &A[j]);
    return j;
}

void quicksort(int A[], int l, int h) {
    if (l < h) {
        int j = partition(A, l, h);

        // Print the pivot
        printf("pivot: %d\n", A[j]);

        // Print the current pass
        printf("pass: ");
        for (int k = l; k <= h; k++) {
            if (k == j) {
                printf("[%d] ", A[k]);
            } else {
                printf("%d ", A[k]);
            }
        }
        printf("\n");

        quicksort(A, l, j - 1);
        quicksort(A, j + 1, h);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the elements in the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    quicksort(A, 0, n - 1);

    printf("After sorting: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
