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

    static void SpiralLevelOrderTraversal(Node *node);
};

void Node::SpiralLevelOrderTraversal(Node *node) {
    stack<Node*> sLR, sRL;
    sLR.push(node);

    Node *temp = NULL;

    while(!sLR.empty() || !sRL.empty()) {

        while(!sLR.empty()) {
            temp = sLR.top();
            sLR.pop();
            cout << temp->data << " ";
            if(temp->right != NULL) sRL.push(temp->right); // right first
            if(temp->left != NULL) sRL.push(temp->left);
        }

        while(!sRL.empty()) {
            temp = sRL.top();
            sRL.pop();
            cout << temp->data << " ";
            if(temp->left != NULL) sLR.push(temp->left); // left first
            if(temp->right != NULL) sLR.push(temp->right);
        }
    }
    cout << endl;
}

int main() {
    Node *root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->right->left = new Node(3);
    root->right->right = new Node(8);

    Node::SpiralLevelOrderTraversal(root);

    return 0;
}