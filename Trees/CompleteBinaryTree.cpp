#include <bits/stdc++.h>
#define li long long int
using namespace std;

struct Node {
    li data;
    Node *left, *right;

    Node(li data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

li CountNodes(Node *node) {
    if(node == NULL) return 0;
    else return 1 + CountNodes(node->left) + CountNodes(node->right);
}

// Index of root = 0
bool IsCompleteBinaryTree(Node *node, li nodeCount, li index=0) {
    if(node == NULL) return true;
    if(index + 1 > nodeCount) return false;
    return IsCompleteBinaryTree(node->left, nodeCount, 2 * index + 1) 
        && IsCompleteBinaryTree(node->right, nodeCount, 2 * index + 2);
}

int main() {
    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    cout << IsCompleteBinaryTree(root, CountNodes(root)) << endl;
}