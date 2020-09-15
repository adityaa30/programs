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

    static void BoundaryLeft(Node *Node);
    static void BoundaryRight(Node *Node);
    static void PrintLeaves(Node *Node);
    static void BoundaryTraversal(Node *node);
};

void Node::BoundaryLeft(Node *node) {
    // Print in top-down manner
    if(node == NULL || (node->left == NULL && node->right == NULL)) return;
    cout << node->data << ' ';
    if(node->left != NULL) BoundaryLeft(node->left);
    else if(node->right != NULL) BoundaryLeft(node->right);
    // Do nothing for leaf-node
}

void Node::BoundaryRight(Node *node) {
    // Print in bottom-up manner
    // Do nothing for leaf-node
    if(node == NULL || (node->left == NULL && node->right == NULL)) return;
    if(node->right != NULL) BoundaryRight(node->right);
    else if(node->left != NULL) BoundaryRight(node->left);
    cout << node->data << ' ';
}

void Node::PrintLeaves(Node *node) {
    // Print only leaves (inorder traversal here; could also be pre/post order)
    if(node != NULL && node->left == NULL && node->right == NULL) cout << node->data << ' ';
    if(node->left != NULL) PrintLeaves(node->left);
    if(node->right != NULL) PrintLeaves(node->right);
}

void Node::BoundaryTraversal(Node *node) {
    cout << node->data << ' ';
    BoundaryLeft(node->left);
    PrintLeaves(node);
    BoundaryRight(node->right);

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

    Node::BoundaryTraversal(root);
    return 0;
}