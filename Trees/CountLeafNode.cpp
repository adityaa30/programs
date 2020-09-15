#include <bits/stdc++.h>
#define li long long int
using namespace std;

struct Node {
    li data;
    Node *left, *right;

    Node(li _data) {
        data = _data;
        left = NULL;
        right = NULL;
    }

    static void CountLeafNodes(Node *node, li& count);
};

void Node::CountLeafNodes(Node *node, li& count) {
    if(node != NULL && node->left == NULL && node->right == NULL) count++;
    if(node->left != NULL) CountLeafNodes(node->left, count);
    if(node->right != NULL) CountLeafNodes(node->right, count);
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

    li count = 0;
    Node::CountLeafNodes(root, count);
    cout << "Count of Leaf nodes: " << count << endl;
    return 0;
}