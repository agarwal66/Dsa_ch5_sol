// Ram is a software engineer working on a project that requires him to efficiently sort a list of names in non-decreasing order. He has decided to implement the heap sort algorithm to accomplish this task.



// Can you help him by writing a program that takes a list of names as input, sorts them using Heap Sort with max heap, and outputs the sorted names in non-decreasing order?

// Input format :
// The first line of input contains an integer 'n', representing the number of names to be sorted.

// The second line of input contains strings, each representing a name.

// Output format :
// The output displays a sorted name in non-decreasing order (ascending order), separated by a space.

// Code constraints :
// The testcases will fall under the following constraints:

// 1 ≤ n ≤ 10

// The names are composed of lowercase and/or uppercase letters and have a maximum length of 50 characters.

// The input names are case-sensitive.
#include <iostream>
using namespace std;
#include <string>

void heapify(string arr[], int n, int i) 
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
       heapify(arr, n, largest);
    }
}


void buildMaxHeap(string arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(string arr[], int n) 
{
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main() {
    int n;
    cin >> n;
    string arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}