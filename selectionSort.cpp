#include <iostream>
using namespace std;

// Function to find the index of the minimum element in the array from index start to n-1
int findMinIndex(int *arr, int start, int n) {
    int minIndex = start;
    for (int i = start + 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Recursive function to perform selection sort
void selectionSort(int *arr, int n, int index = 0) {
    // Base case: If index has reached the end of the array
    if (index == n - 1) {
        return;
    }

    // Find the minimum element in the unsorted part of the array
    int minIndex = findMinIndex(arr, index, n);

    // Swap the found minimum element with the first element of the unsorted part
    if (minIndex != index) {
        swap(arr[minIndex], arr[index]);
    }

    // Recursively call selection sort on the remaining unsorted part of the array
    selectionSort(arr, n, index + 1);
}

int main() {
    int arr[5] = {2, 5, 1, 6, 10};

    selectionSort(arr, 5);

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
