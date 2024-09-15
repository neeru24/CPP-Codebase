#include<iostream>
using namespace std;

// Function to merge two sorted arrays and count inversions
int merge(int *arr, int s, int e) {
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // Copy values to temporary arrays
    int mainArrayIndex = s;
    for(int i = 0; i < len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for(int i = 0; i < len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    // Merge two sorted arrays and count inversions
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;
    int invCount = 0;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] <= second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        } else {
            arr[mainArrayIndex++] = second[index2++];
            invCount += (len1 - index1); // Count inversions
        }
    }

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

    return invCount;
}

// Function to perform merge sort and count inversions
int mergeSort(int *arr, int s, int e) {
    if(s >= e) {
        return 0;
    }

    int mid = (s + e) / 2;
    int invCount = 0;

    invCount += mergeSort(arr, s, mid);
    invCount += mergeSort(arr, mid + 1, e);

    invCount += merge(arr, s, e);

    return invCount;
}

int main() {
    int arr[15] = {3, 7, 0, 1, 5, 8, 3, 2, 34, 66, 87, 23, 12, 12, 12};
    int n = 15;

    int inversionCount = mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Number of inversions: " << inversionCount << endl;

    return 0;
}
