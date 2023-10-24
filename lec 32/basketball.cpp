// A basketball team consisting of N players is gathered at the court, eagerly awaiting their coach's arrival. When the coach finally arrives, he instruct the players to arrange themselves in ascending order of their respective weights. To efficiently check whether the players have complied with this instruction, the coach decides to use a min-heap data structure for verification.



// Explanation

// Min heap is the concept that the parent node should be greater than the left and right children nodes

// In an array, if a[i] is the parent value, a[(i*2)+1] is the left value and a[(i*2)+2] is the right value

// Hence, a[i] should be greater than a[(i*2)+1] and a[(i*2)+2]



// Example

// Input:

// 5

// 78 83 72 70 75 



// Output

// The players are not arranged in min heap order



// Input:

// 5

// 70 72 74 76 78 



// Output:

// The players are arranged in min heap order

// Input format :
// The first line of input consists of an integer n denoting the number of players

// The second line of input consists of the weights of n players, separated by a space.

// Output format :
// The output should print the following statement based on the order of the input values:

// If the values inserted satisfy the property of min-heap, then print "The players are arranged in min heap order".

// If the values inserted do not satisfy the property of min-heap, then print "The players are not arranged in min heap order".



// Refer to the sample output for formatting specifications.

// Code constraints :
// The test cases fall under the following constraints:

// 1<=n<=10
#include <iostream>
using namespace std;
int min_heap(int a[],int n) 
{
    for(int i=0;i<n;i++){
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;
    if(leftChild < n && a[i] > a[leftChild]){
       return 0;//for min_heap
    }
    if(rightChild < n && a[i] > a [rightChild]){
        return 0;
    }
   
    }
    return 1;//non min_heap
}
int main() {
    int n;
    cin>>n;
    int keys[n];
    for (int i = 0; i < n; i++) {
        cin>>keys[i];
    }
    if(min_heap(keys, n)==1)
    {
        cout<<"The players are arranged in min heap order";
    }
    else 
    {
        cout<<"The players are not arranged in min heap order";
    }
}