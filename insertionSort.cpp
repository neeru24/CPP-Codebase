#include<iostream>
using namespace std;

void insertionSort(int *arr, int n) {
    // Base case: If array is of size 1 or 0, it is already sorted
    if(n <= 1) {
        return;
    }

    // Sort the first n-1 elements
    insertionSort(arr, n-1);

    // Insert the nth element in the sorted array
    int last = arr[n-1];
    int j = n-2;

    // Move elements of arr[0..n-1], that are greater than last, to one position ahead of their current position
    while (j >= 0 && arr[j] > last) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}

int main() {
    int arr[5] = {2, 5, 1, 6, 10};

    insertionSort(arr, 5);

    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
