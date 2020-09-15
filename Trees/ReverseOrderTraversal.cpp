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

    static void ReverseOrderTraversal(Node *node);
};

void Node::ReverseOrderTraversal(Node *node) {
    stack<li> s;
    queue<Node*> q;
    q.push(node);
    
    Node* temp = NULL;
    while(!q.empty()) {
        temp = q.front();
        q.pop();

        s.push(temp->data);
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }

    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << endl;
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

    Node::ReverseOrderTraversal(root);
    return 0;
}