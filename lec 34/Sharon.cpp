// Sharon is given a task to develop a program for managing a binary search tree (BST). This program allows her to build, modify, and visualize a BST.



// Create a Binary Search Tree (BST): Implement the functionality to construct a binary search tree by inserting a sequence of integer values into it.
// Find and Delete a Node: Enable the program to locate and delete a node within the BST that corresponds to a specified integer value.
// Display the Modified BST: After performing the deletion operation, display the BST with the remaining nodes using an in-order traversal, which will print the nodes in ascending order.
// Input format :
// The first line of input consists of an integer N, representing the number of nodes to be inserted into the binary search tree (BST).

// The second line consists of N space-separated integers, representing the values to be inserted into the BST.

// The third line consists of a single integer key, representing the value of the node to be deleted from the BST.

// Output format :
// The output prints the following:

// The values of the nodes in the BST, using an in-order traversal.
// The values of the nodes in the BST after deletion, using an in-order traversal.
// You are using GCC
#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* findMinNode(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

 TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return root;
    }

    // Search for the node to delete
    if (key < root->value) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->value) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found, now delete it
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* minRight = findMinNode(root->right);
        root->value = minRight->value;
        root->right = deleteNode(root->right, minRight->value);
    }

    return root;
}


void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->value << " ";
        inorderTraversal(root->right);
    }
}

TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) {
        TreeNode* newNode = new TreeNode();
        newNode->value = key;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    if (key < root->value) {
        root->left = insert(root->left, key);
    } else if (key > root->value) {
        root->right = insert(root->right, key);
    }

    return root;
}

int main() {
    TreeNode* root = nullptr;
    int n, val, key;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> val;
        root = insert(root, val);
    }

    inorderTraversal(root);
    std::cout << std::endl;

    std::cin >> key;

    // Delete the node with the given value
    TreeNode* result = deleteNode(root, key);
    inorderTraversal(result);
    std::cout << std::endl;
    

    return 0;
}