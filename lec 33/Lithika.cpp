// Lithika is a curious computer science enthusiast who has been exploring heaps and their operations. She wants to experiment with a Max Heap and observe its behavior when extracting the maximum element.



// she wants to perform the following operations:



// Build a Max Heap from the given array.
// Extract the maximum element from the Max Heap.
// Display the array after the maximum element is removed.


// Write a program to help Lithika with her experiment.

// Input format :
// The first line contains an integer, n, representing the number of elements in the array.

// The next line contains n space-separated integers, arr [i], representing the elements of the initial array.

// Output format :
// The first line of output displays the maximum element extracted from the Max Heap on the first line.

// The second line of output displays the elements of the array after removing the maximum element on the second line. Separate the elements by spaces.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 <= n <= 10

// 1 <= arr[i] <= 100
#include <iostream>
using namespace std;

#define MAX_SIZE 100

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
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int extractMax(int arr[], int& n) {
    if (n <= 0)
        return -1;

    int maxElement = arr[0];
    arr[0] = arr[n - 1];
    n--;

    heapify(arr, n, 0);

    return maxElement;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

int main() {
    int n;
    cin >> n;

    int arr[MAX_SIZE];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    buildMaxHeap(arr, n);

    int maxElement = extractMax(arr, n);
    if (maxElement != -1) {
        cout << maxElement << endl;
    }

    printArray(arr, n);

    return 0;
}
