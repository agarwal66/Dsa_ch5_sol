// Dustin is learning about data structures and algorithms in his computer science class. Recently, he came across the concept of a Max Heap. To practice his understanding, he decided to implement a Max Heap and test it using a program.



// Write a program that performs the following tasks:



// Create a Max Heap from a given list of integers.
// Remove and print the maximum element from the Max Heap.
// After rearranging the heap, print the current order of it.


// Dustin needs your help to design this program. Help him solve the program.

// Input format :
// The first line consists of an integer n, representing the number of elements in the list.

// The next line contains n space-separated integers where each integer represents an element of the list.

// Output format :
// If the input is invalid (negative or zero), the output prints "Invalid number of elements."

// If the input is valid,

// The first line prints the maximum element removed from the Max Heap.
// After rearranging the heap, the second line prints the elements of the Max Heap in their current order.


// Refer to the sample output for a better understanding.

// Code constraints :
// 1 ≤ n ≤ 10

// 1 ≤ Elements ≤ 100
#include <iostream>

using namespace std; 

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

int removeMax(int arr[], int& n) {
    if (n <= 0)
        return -1;

    int maxElement = arr[0];

    arr[0] = arr[n - 1];
    n--;

    maxHeapify(arr, n, 0);

    return maxElement;
}

int main() {
    int* heap = nullptr;
    int n;

    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of elements." << endl;
        return 0;
    }

    heap = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }

    if (n > 0) {  
        for (int i = n / 2 - 1; i >= 0; i--) {
            maxHeapify(heap, n, i);
        }

        int maxElement = removeMax(heap, n);

        cout << maxElement << endl;
    }

    for (int i = 0; i < n; i++)
        cout << heap[i] << " ";
    cout << endl;

    delete[] heap;

    return 0;
}
