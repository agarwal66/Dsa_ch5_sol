
// ﻿Priya has a garden with different types of flowers, and they are arranged in a max heap based on their height, with the tallest flower at the top. Write a program that helps Priya delete the tallest flower from the garden for pruning and display the remaining heights of the flowers in the garden.

// Input format :
// The first consists of an integer n representing the number of flowers in the garden.

// The second line consists of n space-separated integers representing the heights of each flower.

// Output format :
// After pruning the tallest flower, the program displays the heights of the remaining flowers separated by spaces.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 100

// 1 ≤ Heights ≤ 100
 //----------1st appproach
 #include <iostream>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void heapifyDown(int *heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest]) {
        largest = left;
    }

    if (right < n && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapifyDown(heap, n, largest);
    }
}

void deleteTallestFlower(int *heap, int &n) {
    if (n <= 0) {
        cout << "No flowers to delete." << endl;
        return;
    }
    swap(heap[0], heap[n - 1]);
    n--;

    heapifyDown(heap, n, 0);
}

int main() {
    int *heap;
    int n;
    cin >> n;
    heap = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(heap, n, i);
    }

    deleteTallestFlower(heap, n);

    for (int i = 0; i < n; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
    delete[] heap;
    return 0;
}

//2---Approach 
#include <iostream>
using namespace std;
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void heapifyDown(int *heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapifyDown(heap, n, largest);
    }
}

void deleteTallestFlower(int *heap, int &n) {
    swap(heap[0], heap[n - 1]);
    n--;

    heapifyDown(heap, n, 0);
}

int main() {
    int *heap;
    int n;
    cin >> n;
    heap = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(heap, n, i);
    }

    deleteTallestFlower(heap, n);

    for (int i = 0; i < n; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
    delete[] heap;
    return 0;
}