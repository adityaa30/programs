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


bool IsFoldableUtil(Node *node1, Node *node2) {
    if(node1 == NULL && node2 == NULL) return true; 
    if(node1 == NULL || node2 == NULL) return false;
    return IsFoldableUtil(node1->left, node2->right) 
        && IsFoldableUtil(node1->right, node2->left);
}


bool IsFoldable(Node *node) {
    if(node == NULL) return true;
    return IsFoldableUtil(node->left, node->right) 
        && IsFoldableUtil(node->right, node->left);
}

int main() {
    Node *root = new Node(1);  
    root->left = new Node(2);  
    root->right = new Node(3);  
    root->left->left = new Node(4);  
    root->right->right = new Node(5);  
    // root->right->left = new Node(6);  
    // root->left->left->left = new Node(7);  

    cout << IsFoldable(root) << endl;
}