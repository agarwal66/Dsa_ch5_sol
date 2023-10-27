
// Ethan is working on an employee assignment management system for a company. Employees are assigned tasks based on their expertise and workload. He needs to implement a program that allows for the assignment of tasks to employees while ensuring that the employees with the highest expertise are assigned tasks first.



// Write the function to help him insert a new task (an integer representing the complexity of task) into a max heap.

// Input format :
// The input consists of a series of space-separated integers, representing the complexity of tasks, and inserts them into the max heap.

// Output format :
// The output prints the max heap after each task insertion, showing the current state of the heap.

// Code constraints :
// The maximum heap size is 100 (defined by maxHeapSize).
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertTask(int heap[], int& heapSize, int newTask) {
    int currentIndex;
    if (heapSize < 100) {
        heap[heapSize] = newTask;
        currentIndex = heapSize;
        heapSize++;

        while (currentIndex > 0 && heap[currentIndex] > heap[(currentIndex - 1) / 2]) {
            swap(heap[currentIndex], heap[(currentIndex - 1) / 2]);
            currentIndex = (currentIndex - 1) / 2;
        }
    } else {
        cout << "Heap is full, cannot insert more tasks." << endl;
    }
}

void printHeap(int heap[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int maxHeapSize = 100;
    int maxHeap[maxHeapSize];
    int heapSize = 0;

    while (true) {
        int newTask;
        if (!(cin >> newTask)) {
            break;
        }

        if (heapSize < maxHeapSize) {
            insertTask(maxHeap, heapSize, newTask);
        } else {
            cout << "Heap is full, cannot insert more tasks." << endl;
            break;
        }
    }

    printHeap(maxHeap, heapSize);
    return 0;
}
