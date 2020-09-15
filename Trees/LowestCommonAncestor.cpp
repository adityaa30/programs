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

    static Node* LCA(Node *node, li n1, li n2);
    static li LCATraverse(Node *node, li n1, li n2);
    static bool FindPath(Node *node, vector<li>& path, li n1);
};

bool Node::FindPath(Node *node, vector<li>& path, li n1) {
    if(node == NULL) return false;
    path.push_back(node->data);
    if(node->data == n1) return true;
    if((node->left != NULL && FindPath(node->left, path, n1)) 
        || (node->right != NULL && FindPath(node->right, path, n1))) return true;
    path.pop_back();
    return false;
}

void PrintVector(vector<li> v) {
    for(auto i : v) {
        cout << i << ' ';
    }
    cout << endl;
}

li Node::LCATraverse(Node* node, li n1, li n2) {
    if(node == NULL) return -1;
    vector<li> path1, path2;
    if(FindPath(node, path1, n1) && FindPath(node, path2, n2)) {
        li i = 0, lastPopped = -1;
        while(path1[i] == path2[i] && path1.size() >= 0 && path2.size() >= 0) {
            lastPopped = path1[i];
            i++;
        }
        return lastPopped;
    } else return -1;
}

Node* Node::LCA(Node *node, li n1, li n2) {
    if(node == NULL) return NULL;
    if(node->data == n1 || node->data == n2) return node;

    Node* left = LCA(node->left, n1, n2);
    Node* right = LCA(node->right, n1, n2);

    if(left != NULL && right != NULL) return node;
    return left != NULL ? left : right;
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
    Node* ans = Node::LCA(root, 2, 7); 
    cout << (ans ? ans->data : -1) << endl;
    cout << Node::LCATraverse(root, 2, 7) << endl;
    return 0;
}