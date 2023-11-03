
// Geetha is exploring the world of binary search trees (BSTs) and wants to create a program to find the sum of all nodes in a BST that are greater than a given target value.



// She has implemented a program to accomplish this and needs a problem statement for her task.

// Input format :
// The first line of input consists of an integer, n, representing the number of nodes in the BST.

// The second line of input consists of an integer, denoting the values to be inserted into the BST.

// The last line of input consists of a single integer, target, which is the target value.

// Output format :
// The output displays a single integer, which is the sum of all nodes in the BST with values greater than the target value.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->left = node->right = nullptr;
    return node;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return create(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

int sumGtr(Node* root, int value) {
    if (root == nullptr) {
        return 0;
    }

    if (root->data > value) {
        return root->data + sumGtr(root->left, value) + sumGtr(root->right, value);
    } else {
        return sumGtr(root->right, value);
    }
}

int main() {
    Node* root = nullptr;
    int n, data, target;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insert(root, data);
    }

    cin >> target;

    int sum = sumGtr(root, target);
    cout << sum;

    return 0;
}