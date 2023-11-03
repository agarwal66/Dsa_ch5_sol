// Sarah is developing a ride-sharing app and needs to manage ride requests based on their estimated pick-up times. She wants to implement a program that can insert new ride requests, each represented by an estimated pick-up time, into a min heap.



// Write a program that helps Sarah insert new ride requests into a min heap. After each insertion, the program should print the current state of the min heap.

// Input format :
// The input consists of a series of space-separated integers, each representing the estimated pick-up time of a ride request.

// Output format :
// The output displays the estimated pick-up times of ride requests in the min heap, separated by spaces.

// Code constraints :
// The maximum number of ride requests that can be inserted is 100, as the min heap has a maximum capacity of 100.

// Sample test cases :
// Input 1 :
// 5 8 3 2 10 1
// Output 1 :
// 1 3 2 8 10 5 
// Input 2 :
// 12 18 7 4 15 9 6
// Output 2 :
// 4 7 6 18 15 12 9 
// You are using GCC
#include <iostream>
using namespace std;
struct RideRequest {
    int estimatedPickUpTime;
};

void swap(RideRequest& a, RideRequest& b) {
    RideRequest temp = a;
    a = b;
    b = temp;
}

    void insertRideRequest(RideRequest heap[], int& heapSize, RideRequest newRequest) {
    heap[heapSize] = newRequest;
    int currentIndex = heapSize;

    while (currentIndex > 0) {
        int parentIndex = (currentIndex - 1) / 2;
        if (heap[currentIndex].estimatedPickUpTime < heap[parentIndex].estimatedPickUpTime) {
            swap(heap[currentIndex], heap[parentIndex]);
            currentIndex = parentIndex;
        } else {
            break;  
        }
    }

    heapSize++;
}

void printHeap(RideRequest heap[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i].estimatedPickUpTime;
        if (i < heapSize - 1) {
            cout << " ";
        }
    }
    cout << endl;
}


int main() {
    RideRequest minHeap[100];
    int heapSize = 0;

    while (true) {
        RideRequest newRequest;
        if (!(cin >> newRequest.estimatedPickUpTime)) {
            break;
        }

        insertRideRequest(minHeap, heapSize, newRequest);
    }
    printHeap(minHeap, heapSize);

    return 0;
}