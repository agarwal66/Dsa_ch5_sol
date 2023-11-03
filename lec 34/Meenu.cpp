// Meenu is developing a program to manage the hierarchical structure of employees within a company. The company's organizational structure is represented as a binary search tree, where each employee is assigned a unique employee ID, and employees are organized based on their supervisor-subordinate relationships.



// The program should enable the creation of this hierarchy by accepting user input and then calculating the total number of employees.

// Input format :
// The first line contains the total number of employees, N.

// The next N lines contain the employee IDs.

// Output format :
// The output displays a single integer representing the total number of nodes (employees) in the binary search tree (company hierarchy).



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 <= n <= 10

// 1 <= employee ID <= 100
// You are using GCC
#include <iostream>
using namespace std;

int n = 1;

struct node
{
    int data;
    node* left;
    node* right;
};

struct node* getNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* Insert(struct node* root, int data)
{
  if(root==nullptr){
      return getNode(data);
  }
   if(data < root->data){
      root->left = Insert(root->left,data);
  }
  else if(data > root->data){
      root->right = Insert(root->right,data);
  }
  return root;
}

int CountNodes(node* root)
{
    
    if(root==nullptr){
        return 0;
    }
    int leftCount = CountNodes(root->left);
    int rightCount = CountNodes(root->right);
    return 1+ leftCount+rightCount;
}

int main()
{
    node* root = NULL;
    int numNodes;

    cin >> numNodes;

    for (int i = 0; i < numNodes; i++) {
        int data;
        cin >> data;
        root = Insert(root, data);
    }

    cout << CountNodes(root) << endl;

    return 0;
}