// The group of archaeologists studying ancient artifacts has presented Mark Antony with a perplexing challenge. They've come across an enigmatic array of elements that appear to depict a min-heap tree, but they are struggling to efficiently extract the largest element from this min-heap.



// Mark Antony's task is to assist them in transforming the provided min-heap array into a max-heap representation. This conversion will facilitate the straightforward retrieval of the largest element from the tree.



// Note: This kind of question will be helpful in clearing Accenture recruitment.

// Input format :
// The first line of input consists of an integer n, representing the number of elements in the min heap tree.

// The second line of input consists of n space-separated integer elements, forming the min heap sequence.

// Output format :
// The output prints the space-separated n integer values of the max heap array formed after the conversion.



// Refer to the sample output for further format specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 < n < 30

// 1 < array elements < 35
#include <iostream>
using namespace std;

void MaxHeapify(int arr[], int i, int N)
{
     int largest = i;
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;
    if(leftChild < N && arr[leftChild] > arr[largest]){
        largest=leftChild;
    }
    if(rightChild < N && arr[rightChild] > arr[largest]){
        largest = rightChild;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        MaxHeapify(arr,largest,N);
    }
}

void convertMaxHeap(int arr[], int N)
{
    for (int i = (N - 2) / 2; i >= 0; --i)
        MaxHeapify(arr, i, N);
}
void printArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout<<endl;
}
int main()

{
    int arrayCount;
    cin>>arrayCount;
    int arr[arrayCount];
    for (int i=0;i<arrayCount;i++){
        cin>>arr[i];
    }
    convertMaxHeap(arr, arrayCount);
    printArray(arr, arrayCount);
    return 0;
}