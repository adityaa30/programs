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

bool CheckIsomorphicTrees(Node *node1, Node *node2) {
    if(node1 == NULL && node2 == NULL) return true;
    else if(node1 == NULL || node2 == NULL) return true;
    else { // both are non-null
        if (node1->data != node2->data) return false;
        return (
            (CheckIsomorphicTrees(node1->left, node2->left) && CheckIsomorphicTrees(node1->right, node2->right))
            || CheckIsomorphicTrees(node1->left, node2->right) && CheckIsomorphicTrees(node1->left, node2->right)
        );
    }
}

int main() {
    Node *root1 = new Node(1);
    root1->left = new Node(2); 
    root1->right = new Node(3); 
    root1->left->left = new Node(4); 
    root1->left->right = new Node(5); 
    root1->right->left = new Node(6); 
    root1->left->right->left = new Node(7); 
    root1->left->right->right = new Node(8); 
  
    Node *root2 = new Node(1); 
    root2->left = new Node(3); 
    root2->right = new Node(2); 
    root2->right->left = new Node(4); 
    root2->right->right = new Node(5); 
    root2->left->right = new Node(6); 
    root2->right->right->left = new Node(8); 
    root2->right->right->right = new Node(7); 

    cout << CheckIsomorphicTrees(root1, root2) << endl;
  
    return 0;
}