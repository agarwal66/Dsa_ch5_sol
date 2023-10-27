
// Krish wants to sort a list of integers using the heap sort algorithm. He needs your help to implement this algorithm and is looking for a program that can take a list of integers as input, sort them in descending order using heap sort with max heap, and then print the sorted list.

// Input format :
// The first line of input consists of an integer n, the number of elements in the array.

// The second line of input consists of n elements, separated by a space.

// Output format :
// The output displays a single line containing n space-separated integers, which represent the sorted list of integers in descending order.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 <= n <= 10

// 1 <= elements <= 100
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapSort(arr, n);

    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }

    return 0;
}
