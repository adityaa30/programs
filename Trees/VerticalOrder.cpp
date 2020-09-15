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
    
    static void PrintMap(map<li, vector<li>> m) {
        for(auto i = m.begin(); i != m.end(); ++i) {
            cout << i->first << ": ";
            for(auto j : i->second) cout << j << " ";
            cout << endl;
        }
    }

    static void PrintMap(map<li, li> m) {
        for(auto i = m.begin(); i != m.end(); ++i) cout << i->first << ": " << i->second << endl;
    }

    static void VerticalOrderTraversal(Node *node, map<li, vector<li>>& m, li horizontalDistance);
    static void VerticalOrderSum(Node *node, map<li, li>& m, li horizontalDistance);
    static void VerticalWidth(Node *node, li& minimum, li& maximum, li horizontalDistance);
};

void Node::VerticalOrderTraversal(Node *node, map<li, vector<li>>& m, li horizontalDistance=0) {
    m[horizontalDistance].push_back(node->data);

    if(node->left != NULL) VerticalOrderTraversal(node->left, m, horizontalDistance - 1);
    if(node->right != NULL) VerticalOrderTraversal(node->right, m, horizontalDistance + 1);
}

void Node::VerticalOrderSum(Node *node, map<li, li>& m, li horizontalDistance) {
    m[horizontalDistance] += node->data;

    if(node->left != NULL) VerticalOrderSum(node->left, m, horizontalDistance - 1);
    if(node->right != NULL) VerticalOrderSum(node->right, m, horizontalDistance + 1);
}

void Node::VerticalWidth(Node *node, li& minimum, li& maximum, li horizontalDistance) {
    minimum = min(minimum, horizontalDistance);
    maximum = max(maximum, horizontalDistance);
    
    if(node->left != NULL) VerticalWidth(node->left, minimum, maximum, horizontalDistance - 1);
    if(node->right != NULL) VerticalWidth(node->right, minimum, maximum, horizontalDistance + 1);
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

    map<li, vector<li>> m1;
    Node::VerticalOrderTraversal(root, m1, 0);
    Node::PrintMap(m1);
    cout << endl;
    map<li, li> m2;
    Node::VerticalOrderSum(root, m2, 0);
    Node::PrintMap(m2);

    li minimum = 0, maximum = 0;
    Node::VerticalWidth(root, minimum, maximum, 0);
    cout << "Vertical width: " << (abs(minimum) + maximum + 1) << endl;
}