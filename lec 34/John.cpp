// ohn, a computer science student, is studying Binary Search Trees (BSTs) as part of his coursework. He is fascinated by these data structures and wants to create a program that enables users to construct a Binary Search Tree and subsequently remove all the leaf nodes from the tree.



// Help John develop this program to practice his newfound knowledge.

// Input format :
// The first line of input consists of an integer, N, representing the number of nodes to insert into the BST.

// The second line contains N space-separated integers representing the values of the BST nodes to be inserted.

// Output format :
// The output displays the values of the BST in ascending order after removing all the leaf nodes.

// If the tree is empty, print "Empty tree."



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The given test cases will fall under the following constraint:



// 1 <= N <= 10

// The input values are unique positive integers.

// Sample test cases :
// Input 1 :
// 4
// 5 3 7 2
// Output 1 :
// 3 5 
// Input 2 :
// 5
// 3 1 6 2 7
// Output 2 :
// 1 3 6 
// Input 3 :
// 3
// 5 2 7
// Output 3 :
// 5 
// Input 4 :
// 0
// Output 4 :
// Empty tree

// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int key) {
    if (root == NULL) return createNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

void printInOrder(struct TreeNode* root) {
    if (root == NULL) 
    return;
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

struct TreeNode* deleteLeafNodes(struct TreeNode* root) {
    if (root == NULL) return NULL;
    
    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }
    
    root->left = deleteLeafNodes(root->left);
    root->right = deleteLeafNodes(root->right);
    
    return root;
}

int main() {
    int N;
    scanf("%d", &N);

    struct TreeNode* root = NULL;
    
    for (int i = 0; i < N; i++) {
        int key;
        scanf("%d", &key);
        root = insert(root, key);
    }

    root = deleteLeafNodes(root);
    
    if (root == NULL) {
        printf("Empty tree\n");
    } else {
        printInOrder(root);
        printf("\n");
    }

    return 0;
}