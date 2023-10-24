// You have a passion for T20 cricket matches and are eager to monitor the performance of bowlers to determine this year's recipient of the purple cap. To streamline this process, you wish to create an application that stores the data in a heap, specifically a max heap. This will enable you to easily identify the bowler with the highest number of wickets.



// Write a program that takes in integers representing the wickets taken by different bowlers and generates a max heap representation of the same.



// Note: This kind of question will be helpful in clearing TCS recruitment.

// Input format :
// The first line of input consists of an integer n, representing the total number of bowlers.

// The second line of input consists of n space-separated integer values representing the number of wickets taken by the bowlers.

// Output format :
// The output displays the space-separated integer values of the max-heap specifying the total number of wickets taken by the bowler.



// Refer to the sample output for exact format specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 1<=n<=5

// 1<=number of wickets <=10
#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int> &heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap.size() && heap[left] > heap[largest])
        largest = left;

    if (right < heap.size() && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        maxHeapify(heap, largest);
    }
}

void buildMaxHeap(vector<int> &heap) {
    for (int i = heap.size() / 2 - 1; i >= 0; i--) {
        maxHeapify(heap, i);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> wickets(n);

    for (int i = 0; i < n; i++) {
        cin >> wickets[i];
    }

    // Build a max-heap
    buildMaxHeap(wickets);

    // Output the max-heap
    for (int i = 0; i < n; i++) {
        cout << wickets[i];
        if (i < n - 1)
            cout << " ";
    }

    return 0;
}
