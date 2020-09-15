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

    static void LeftView(Node *node, li level, li& maxLevel);
};

void Node::LeftView(Node *node, li level, li& maxLevel) {
    if(node == NULL) return;
    if(level > maxLevel) {
        cout << node->data << ' ';
        maxLevel = level;
    }

    if(node->left != NULL) LeftView(node->left, level + 1, maxLevel);
    if(node->right != NULL) LeftView(node->right, level + 1, maxLevel);
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->right->right = new Node(6);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);

    li maxLevel = -1;
    Node::LeftView(root, 0, maxLevel);
    return 0;
}