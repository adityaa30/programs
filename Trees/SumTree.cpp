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

bool isLeaf(Node *node) {
    if(node == NULL) return false;
    else if(node->left == NULL && node->right == NULL) return true;
    return false;
}

bool CheckSumTree(Node *node) {
    if(node == NULL || isLeaf(node)) return true;

    if(CheckSumTree(node->left) && CheckSumTree(node->right)) {
        li leftSum = 0, rightSum = 0;
        if (node->left == NULL) leftSum = 0;
        else if(isLeaf(node->left)) leftSum = node->left->data;
        else leftSum = 2 * node->left->data;

        if (node->right == NULL) rightSum = 0;
        else if(isLeaf(node->right)) rightSum = node->right->data;
        else rightSum = 2 * node->right->data;

        return node->data == (leftSum + rightSum);
    }
    return false;
}

li ConvertToSumTree(Node *node) {
    if(node == NULL) return 0;

    li OldVal = node->data;
    node->data = ConvertToSumTree(node->left) + ConvertToSumTree(node->right);
    return OldVal + node->data;
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
    Node *root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(9);

    cout << "SumTree: " << CheckSumTree(root) << endl;
    LevelOrderTraversal(root);
    ConvertToSumTree(root);
    cout << "SumTree: " << CheckSumTree(root) << endl;
    LevelOrderTraversal(root);
    return 0;
}