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

    static void DoubleTree(Node *node);
    static void Inorder(Node *node);
};

void Node::DoubleTree(Node *node) {
    if(node->left != NULL) DoubleTree(node->left);
    if(node->right != NULL) DoubleTree(node->right);

    Node *temp = node->left;
    node->left = new Node(node->data);
    node->left->left = temp;
}

void Node::Inorder(Node *node) {
    if(node != NULL) {
        if(node->left != NULL) Inorder(node->left);
        cout << node->data << ' ';
        if(node->right != NULL) Inorder(node->right);
    }
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    Node::Inorder(root); cout << endl;
    Node::DoubleTree(root);
    Node::Inorder(root); cout << endl;
    return 0;
}