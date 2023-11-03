// Banu is studying binary search trees (BST) in her computer science class. She needs to write a program to manage BST nodes, including insertion and deletion. Her task is to delete nodes with values greater than a given threshold from a BST.



// You are required to help Banu by implementing a program for this task.

// Input format :
// The first line of input consists of an integer n, the number of nodes in the initial BST.

// The second line of input consists of n space-separated integers, representing the values of the nodes in the initial BST.

// The third line of input consists of an integer v, the threshold value for node deletion.

// Output format :
// The output displays the values of the nodes remaining in the BST after deleting nodes with values greater than the given threshold, in an in-order traversal order.
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* crNode(int d) {
    Node* nN = (Node*)malloc(sizeof(Node));
    nN->data = d;
    nN->left = nN->right = nullptr;
    return nN;
}

Node* insrt(Node* r, int d) {
    if (r == nullptr) {
        return crNode(d);
    }
    if (d < r->data) {
        r->left = insrt(r->left, d);
    } else if (d > r->data) {
        r->right = insrt(r->right, d);
    }
    return r;
}

Node* dltGt(Node* r, int v) {
    if (r == nullptr) {
        return nullptr;
    }
    r->left = dltGt(r->left, v);
    r->right = dltGt(r->right, v);

    if (r->data > v) {
        Node* t = r;
        r = nullptr;
        free(t);
    }
    return r;
}

void iOT(Node* r) {
    if (r != nullptr) {
        iOT(r->left);
        cout << r->data << " ";
        iOT(r->right);
    }
}

int main() {
    Node* r = nullptr;
    int n, d, v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> d;
        r = insrt(r, d);
    }

    cin >> v;

    r = dltGt(r, v);

    iOT(r);

    return 0;
}
