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

bool IsBST(Node *node) {
    if(node == NULL) return true;

    if(IsBST(node->left) && IsBST(node->right)) {
        if(node->left != NULL && node->right != NULL) 
            return (node->left->data < node->data && node->right->data > node->data);
        else if(node->left == NULL && node->right != NULL) {
            return (node->right->data > node->data);
        }
        else if(node->left != NULL && node->right == NULL) {
            return (node->left->data < node->data);
        } else {
            return true; // leaf
        }
    }
    return false;
}

int main() {
    Node *root = new Node(100);
    root->left = new Node(50);
    root->left->left = new Node(25);
    root->left->right = new Node(75);
    root->right = new Node(150);
    root->right->left = new Node(125);
    root->right->right = new Node(200);

    cout << IsBST(root) << endl;
}