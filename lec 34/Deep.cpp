// Deep within the mystical Enchanted Garden, there exists a wondrous tree known as the "Evenness Emissary." Legend has it that this magical tree holds the secrets to unlocking hidden powers in even numbers. 



// To harness these powers, craft a program by creating a magical Binary Search Tree (BST) in the garden and discovering the even values hidden within its branches by using the inorder traversal.

// Input format :
// The first line of input consists of an integer N, representing the number of seeds.

// The second line consists of a set of N unique integers representing the enchanted seeds to be planted in the Evenness Emissary.

// Output format :
// The output displays the even values obtained by performing an in-order traversal on the Evenness Emissary.

// Code constraints :
// 1 ≤ N ≤ 100\
// You are using GCC
#include <iostream>

// Structure for a node in the BST
struct Node {
    int key;
    Node* left;
    Node* right;
    
    // Constructor
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

// Function to insert a key into the BST
Node* insert(Node* root, int key) {
    //Type your code here
    if(root==nullptr){
        return new Node(key);
    }
    else if(key < root->key){
        root->left = insert(root->left,key);
    }
    else if(key> root->key){
        root->right = insert(root->right,key);
    }
    return root;
    
}

// Function to perform inorder traversal and print even values
void inorderPrintEven(Node* root) {
    if (root == nullptr) {
        return; 
    }
    
    inorderPrintEven(root->left); 
    if (root->key % 2 == 0) {
        std::cout << root->key << " ";
    }
    
    inorderPrintEven(root->right);
}

// Main function for testing
int main() {
    int n;
    std::cin >> n;
    Node* emissary = nullptr;
    // Plant the enchanted seeds
    for (int i = 0; i < n; i++) {
        int seed;
        std::cin >> seed;
        emissary = insert(emissary, seed);
    }
    inorderPrintEven(emissary);

    return 0;
}