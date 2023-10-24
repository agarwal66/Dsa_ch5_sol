
// Isabella is working on a scheduling algorithm for a job queue. Each job has an associated priority value, and she needs to create a function to insert a new job, represented by an integer priority, into a min heap.



// Write a code to help her insert a new job (an integer representing priority) into a min heap.

// Input format :
// The input consists of a series of space-separated integers, each representing the priority of a new job to be inserted into the min heap.

// Output format :
// The output displays the priorities of the jobs after each insertion into the min heap. The priorities are separated by spaces.

// Code constraints :
// The maximum number of jobs that can be inserted is 100, as the min heap has a maximum capacity of 100.
#include <iostream>
using namespace std;

struct Job {
    int priority;
};

void swap(Job& a, Job& b) {
    Job temp = a;
    a = b;
    b = temp;
}

void insertJob(Job heap[], int& heapSize, int newJobPriority) {
     int currentIndex;
     Job newJob;
     newJob.priority = newJobPriority;
        heap[heapSize] = newJob;
        currentIndex = heapSize;

        while (currentIndex > 0){
            int parentIndex = (currentIndex-1)/2;
            if( heap[currentIndex].priority < heap[parentIndex].priority) {
            swap( heap[currentIndex],  heap[parentIndex]);
            currentIndex = parentIndex;
    } 
    else {
       break;
    }
}
heapSize++;
}
void printHeap(Job heap[],int heapSize){
    for(int i=0;i<heapSize;i++){
        cout<<heap[i].priority;
        if(i < heapSize-1){
            cout<<" ";
        }
    }
    cout<<endl;
}


int main() {
    Job minHeap[100];
    int heapSize = 0;

    while (true) {
        int newJobPriority;
        if (!(cin >> newJobPriority)) {
            break;
        }

        insertJob(minHeap, heapSize, newJobPriority);
    }

    printHeap(minHeap, heapSize);

    return 0;
}