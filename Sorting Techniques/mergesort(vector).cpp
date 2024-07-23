#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr) {
    for (int element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner //
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transferring all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    cout << "Merged Pass: ";
    printArray(arr);
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);        // left half
    mergeSort(arr, mid + 1, high);    // right half
    merge(arr, low, mid, high);       // merging sorted halves
}

void removeDuplicates(vector<int> &arr) {
    int n = arr.size();
    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n - 1];
    arr.resize(j);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Randomly generated elements: ";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        cout <<  arr[i] << " ";
    }
    cout << endl;

    cout << "Before Sorting Array: " << endl;
    printArray(arr);

    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout<< endl << "After Sorting Array: " << endl;
    printArray(arr);
    cout << "Array length before removing duplicates: " << arr.size() << endl;

    cout << "Sorted array without duplicates: " << endl;
    removeDuplicates(arr);
    printArray(arr);
    cout << "Array length after removing duplicates: " << arr.size() << endl;

    cout << "Time taken for merge sort: " << duration.count() << " milliseconds" << endl;

    return 0;
}
