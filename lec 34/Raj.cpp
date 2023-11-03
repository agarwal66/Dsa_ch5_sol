// Raj is learning about Binary Search Trees (BSTs) in his computer science class. He's particularly interested in verifying whether a given tree is a Binary Search Tree (BST) or not.



// A Binary Search Tree (BST) is a node-based binary tree data structure that has the following properties:



// The left subtree of a node contains only nodes with keys less than the node’s key. 
// The right subtree of a node contains only nodes with keys greater than the node’s key.
// Both the left and right subtrees must also be binary search trees.
// Each node (item in the tree) has a distinct key.


// Your task is to write a program that will help Raj verify if a given tree is a BST.

// Input format :
// The first line of input consists of an integer N, the number of nodes in the binary search tree.

// The second line of input consists of N space-separated integers, the values of the nodes in the binary search tree.

// Output format :
// The output displays the following format:



// "The tree is a Binary Search Tree" if the given tree is a BST.
// "The tree is not a Binary Search Tree" if the given tree is not a BST.


// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:
#include <iostream>
#include <cstdlib> // Include for malloc and free
#include <climits>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == nullptr) {
        exit(1);
    }
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }

    return root;
}

int isBST(TreeNode* root, int min_val, int max_val) {
    if (root == nullptr) {
        return 1; 
    }

    if (root->value <= min_val || root->value >= max_val) {
        return 0; 
    }

    return isBST(root->left, min_val, root->value) && isBST(root->right, root->value, max_val);
}

int main() {
    TreeNode* root = nullptr;

    int num_nodes;
    cin >> num_nodes;

    for (int i = 0; i < num_nodes; i++) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    if (isBST(root, INT_MIN, INT_MAX)) {
        cout << "The tree is a Binary Search Tree";
    }
    else {
        cout << "The tree is not a Binary Search Tree";
    }

    free(root);

    return 0;
}
