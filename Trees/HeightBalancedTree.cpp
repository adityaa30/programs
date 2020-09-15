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

bool CheckHeightBalanced(Node *node, li& height) {
    if(node == NULL) return true;

    li leftHeight = 0, rightHeight = 0;
    bool leftBalanced, rightBalanced;

    leftBalanced = CheckHeightBalanced(node->left, leftHeight);
    rightBalanced = CheckHeightBalanced(node->right, rightHeight);

    height = max(leftHeight, rightHeight) + 1;

    return leftBalanced && rightBalanced && abs(leftHeight - rightHeight) <= 1;
}

int main() {
    Node *root = new Node(1);  
    root->left = new Node(2);  
    root->right = new Node(3);  
    root->left->left = new Node(4);  
    root->left->right = new Node(5);  
    root->right->left = new Node(6);  
    root->left->left->left = new Node(7);  

    li height = 0;
    cout << CheckHeightBalanced(root, height) << endl;
    cout << height << endl;
}