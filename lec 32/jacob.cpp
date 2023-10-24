
// Jacob is developing a program to manage tasks in a to-do list application. He wants to implement a function to insert a new task's priority into a min heap that represents the tasks' priorities.



// Write a code to help him insert new task priorities into a min heap.

// Input format :
// The input consists of a series of space-separated integers, each representing the priority of a new task to be inserted into the min heap.

// Output format :
// The output displays the priorities of the tasks after each insertion into the min heap. The priorities are separated by spaces.

// Code constraints :
// The maximum number of tasks that can be inserted is 100, as the min heap has a maximum capacity of 100.
//-------1st approach
// You are using GCC
#include <iostream>
using namespace std;

struct Task {
    int priority;
};

void swap(Task& a, Task& b) {
    Task temp = a;
    a = b;
    b = temp;
}

void insertTaskPriority(Task heap[], int& heapSize, Task newTask) {

    int currentIndex;
    heap[heapSize] = newTask;
    currentIndex = heapSize;
    heapSize++;
    while(currentIndex > 0){
        int parentIndex = (currentIndex - 1)/2;
        if(heap[currentIndex].priority < heap[parentIndex].priority){
            swap(heap[currentIndex],heap[parentIndex]);
            currentIndex = parentIndex;
        }
        else{
            break;
    }
}
}
void printHeap(struct Task heap[],int heapSize){
    for(int i=0;i<heapSize;i++){
        cout<<heap[i].priority;
        if(i < heapSize - 1){
            cout<<" ";
        }
    }
    cout<<endl;
}


int main() {
    Task minHeap[100]; 
    int heapSize = 0;

    while (true) {
        Task newTask;
        if (!(cin >> newTask.priority)) {
            break;
        }

        insertTaskPriority(minHeap, heapSize, newTask);
    }
    printHeap(minHeap, heapSize);

    return 0;
}
//------------2nd aproach
#include <iostream>
using namespace std;

struct Task {
    int priority;
};

void swap(Task& a, Task& b) {
    Task temp = a;
    a = b;
    b = temp;
}

// Function to insert a new task priority into the min heap
void insertTaskPriority(Task heap[], int& heapSize, Task newTask) {
    heapSize++;

    int i = heapSize - 1;
    heap[i] = newTask;

    while (i > 0 && heap[(i - 1) / 2].priority > heap[i].priority) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printHeap(Task heap[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i].priority << " ";
    }
    cout << endl;
}

int main() {
    Task minHeap[100];  // Assuming a maximum heap size of 100
    int heapSize = 0;

    while (true) {
        Task newTask;
        if (!(cin >> newTask.priority)) {
            break;
        }

        insertTaskPriority(minHeap, heapSize, newTask);
    }
    printHeap(minHeap, heapSize);

    return 0;
}