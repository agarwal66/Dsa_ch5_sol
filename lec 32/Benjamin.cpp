// Benjamin is developing a print job management system where users submit print jobs with varying importance, and he needs to insert new print jobs into a binary min-heap.



// Write the code to help him insert the print jobs into a binary min-heap.

// Input format :
// The input consists of a series of integers, representing the importance of print jobs, that are to be inserted into the heap.

// Output format :
// The output prints the binary min-heap, after inserting all the print jobs.

// Code constraints :
// The maximum heap size is defined by maxHeapSize (here set to 100).

//-------1ST APPROACH
#include <iostream>
using namespace std;

struct PrintJob {
    int importance;
};

void swap(struct PrintJob* a, struct PrintJob* b) {
    struct PrintJob temp = *a;
    *a = *b;
    *b = temp;
}

void insertPrintJob(struct PrintJob heap[], int* heapSize, struct PrintJob newPrintJob) {
    int currentIndex;
    heap[*heapSize] = newPrintJob;
    currentIndex = (*heapSize)++;
    while(currentIndex > 0){
        int parentIndex = (currentIndex - 1)/2;
        if(heap[currentIndex].importance < heap[parentIndex].importance){
            swap(&heap[currentIndex], &heap[parentIndex]);
            currentIndex = parentIndex;
        }
        else{
            break;
        }
    }
}

void printHeap(struct PrintJob heap[], int heapSize) {
    for(int i=0; i<heapSize; i++) {
        cout << heap[i].importance;
        if(i < heapSize - 1){
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    struct PrintJob binaryHeap[100];
    int heapSize = 0;

    while (1) {
        struct PrintJob newPrintJob;
        if (!(cin >> newPrintJob.importance)) {
            break;
        }

        insertPrintJob(binaryHeap, &heapSize, newPrintJob);
    }

    printHeap(binaryHeap, heapSize);

    return 0;
}

//--------2ND APPROACH
#include <iostream>
using namespace std;

struct PrintJob {
    int importance;
};

void swap(struct PrintJob* a, struct PrintJob* b) {
    struct PrintJob temp = *a;
    *a = *b;
    *b = temp;
}

void insertPrintJob(struct PrintJob heap[], int* heapSize, struct PrintJob newPrintJob) {
    (*heapSize)++;

    int i = (*heapSize) - 1;
    heap[i] = newPrintJob;

    while (i > 0 && heap[(i - 1) / 2].importance > heap[i].importance) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printHeap(struct PrintJob heap[], int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i].importance << " ";
    }
    cout << endl;
}

int main() {
    struct PrintJob binaryHeap[100];
    int heapSize = 0;

    while (1) {
        struct PrintJob newPrintJob;
        if (!(cin >> newPrintJob.importance)) {
            break;
        }

        insertPrintJob(binaryHeap, &heapSize, newPrintJob);
    }

    printHeap(binaryHeap, heapSize);

    return 0;
}
