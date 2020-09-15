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

void Increment(Node *node, li diff) {
    if(node->left) {
        node->left->data += diff;
        Increment(node->left, diff);
    } else if(node->right) {
        node->right->data += diff;
        Increment(node->right, diff);
    }
}

void ConvertToChildrenSum(Node *node) {
    if(node == NULL || (node->left == NULL && node->right == NULL)) return;
    ConvertToChildrenSum(node->left);
    ConvertToChildrenSum(node->right);
    // cout << node->data << ' ';

    li childrenSum = (node->left != NULL ? node->left->data : 0)
            + (node->right != NULL ? node->right->data : 0);
    li diff = childrenSum - node->data;
    if (diff >= 0) node->data += diff;
    else Increment(node, -diff);
}

void LevelOrderTraversal(Node *node) {
    queue<Node*> q;
    q.push(node);
    q.push(NULL);

    Node *temp = NULL;
    while(!q.empty()) {
        temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) q.push(NULL);
        } else {
            cout << temp->data << ' ';
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
    }
    cout << endl;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left = new Node(6);
    root->left->left->left = new Node(7);

    LevelOrderTraversal(root);
    ConvertToChildrenSum(root);
    LevelOrderTraversal(root);
}