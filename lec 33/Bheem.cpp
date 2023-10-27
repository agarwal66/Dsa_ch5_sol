// Bheem has recently started exploring data structures and is now fascinated with heaps, specifically min-heaps. He's working on a problem where he needs to delete a specific element from a min-heap. Can you help him write a program to accomplish this task?



// A min-heap is a specialized binary tree where the parent node has a value smaller than or equal to its child nodes. The goal is to implement a program that can delete a specific element from a given min-heap and maintain the heap's properties



// Write a program to build a min heap, delete a given number from it, and print the min heap after deletion.

// Input format :
// The first line of input contains an integer n, representing the number of elements in the initial min-heap.

// The second line contains n space-separated integers, each representing an element of the min-heap.

// The third line contains an integer key, which is the element Bheem wants to delete from the min-heap.

// Output format :
// The output should consist of a single line with space-separated integers, representing the min-heap after the specified element has been deleted.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ elements ≤ 100

// key must be values present in the min heap
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void minHeapify(int arr[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] < arr[smallest])
        smallest = left;

    if (right < size && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, size, smallest);
    }
}

void buildMinHeap(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(arr, size, i);
    }
}

void deleteElement(int arr[], int& size, int key) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == key)
            break;
    }

    if (i == size)
        return; 
    swap(arr[i], arr[size - 1]); 
    size--;
    minHeapify(arr, size, i);
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    buildMinHeap(arr, n);

    deleteElement(arr, n, key);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
