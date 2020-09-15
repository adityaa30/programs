#include <bits/stdc++.h>
#define li long long int
using namespace std;

struct Node {
    li data;
    Node *left, *right, *next;

    Node(li _data) {
        data = _data;
        left = NULL;
        right = NULL;
        next = NULL;
    }

    static void PopulateNext(Node *node);
    static void PrintNext(Node *node);
};

void Node::PopulateNext(Node *node) {
    static Node* next = NULL;
    if(node != NULL) {
        PopulateNext(node->right);
        node->next = next;
        next = node;
        PopulateNext(node->left);
    }
}

void Node::PrintNext(Node *node) {
    while(node != NULL) {
        cout << (node->next ? node->next->data : -1) << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node *root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->right->right = new Node(8);
    Node::PopulateNext(root);
    Node::PrintNext(root->left);
    return 0;
}