// Romit is a student learning Binary Search Trees (BST). His teacher assigned him the task of creating a program where users input an integer K, the program will find and display the Kth largest element in the BST. If there are not enough elements to find the Kth largest element, it will output "Doesn't exist."



// Write a program to help Romit find the Kth largest element in the BST.

// Input format :
// The first line of input consists of an integer N, representing the number of elements in the BST.

// The second line consists of N space-separated integers, which are the elements in the BST.

// The third line consists of an integer K, which represents the Kth largest element to find.

// Output format :
// The output prints the Kth largest element in the BST, if exists.

// Otherwise, print "Doesn't exist."

// Code constraints :
// The test cases fall under the following constraints:

// 1 ≤ N ≤ 25 (the number of elements in the list)

// 1 ≤ K ≤ N (the Kth largest element to find)

// The elements in the list are unique integers.
// You are using GCC
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void findKthLargest(Node* root, int K, int& count, int& result) {
    if (root == nullptr || count >= K) {
        return;
    }
    findKthLargest(root->right, K, count, result);
    count++;
    if (count == K) {
        result = root->data;
        return;
    }
    findKthLargest(root->left, K, count, result);//yh condition return kradi pass kradi kinda
}
int main() {
    Node* root = nullptr;
    int n, K, count = 0, result;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        if (root == nullptr) {
            root = createNode(data);
        } else {
            Node* current = root;
            while (true) {
                if (data <= current->data) {
                    if (current->left == nullptr) {
                        current->left = createNode(data);
                        break;
                    }
                    current = current->left;
                } else {
                    if (current->right == nullptr) {
                        current->right = createNode(data);
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }

    cin >> K;

    findKthLargest(root, K, count, result);

    if (count < K) {
        cout << "Doesn't exist.";
    } else {
        cout << result;
    }

    return 0;
}