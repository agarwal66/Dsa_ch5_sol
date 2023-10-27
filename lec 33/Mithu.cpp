// Mithu is given an array of integers and a threshold value. He wants to create a max-heap from the given array and then remove all elements from the heap that are greater than the given threshold. After performing these operations, Mithu wants to display the remaining elements in the max-heap.



// Write a program to help Mithu accomplish this task.

// Input format :
// The first line of input consists of an integer n, the number of elements in the array.

// The second line of input consists of n elements separated by spaces.

// The third line of input consists of an integer threshold.

// Output format :
// The output displays the elements of the max-heap after removing all elements greater than the threshold. Separate the elements by spaces.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 <= n <= 12

// 1 <= elements <= 200

// 1 <= threshold <= 200
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void deleteGreaterThanpoint(int arr[], int &n, int threshold) {
    int newSize = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= threshold) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }
    n = newSize;
}

void displayHeap(int arr[], int n) {
    for (int i = 0;i<n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    int threshold;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildMaxHeap(arr, n);

    cin >> threshold;

    deleteGreaterThanpoint(arr, n, threshold);

    displayHeap(arr, n);

    return 0;
}
