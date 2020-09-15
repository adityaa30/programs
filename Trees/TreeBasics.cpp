#include <bits/stdc++.h>
#include <limits.h>
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

    static li GetSize(Node *node);
    static li GetMaxDepth(Node *node);
    static li GetDiameter(Node *node, li& ans);
    static void GetMaxWidthPreorder(Node *node, li *count, li level);
    static li GetMaxWidth(Node *node);
    static bool CheckIdenticalTrees(Node *nodeA, Node *nodeB);
    
    static void InorderTraversal(Node *node);
    static void PreorderTraversal(Node *node);
    static void PostorderTraversal(Node *node);
};

li Node::GetSize(Node *node) {
    if(node == NULL) return 0;
    return GetSize(node->left) + 1 + GetSize(node->right);
}

li Node::GetMaxDepth(Node *node) {
    if(node == NULL) return 0;
    li leftMax = GetMaxDepth(node->left);
    li rightMax = GetMaxDepth(node->right);
    return max(leftMax, rightMax) + 1;
}

li Node::GetDiameter(Node *node, li& ans) {
    // Stores diameter in `ans`
    if(node == NULL) return 0;
    li leftHeight = GetDiameter(node->left, ans);
    li rightHeight = GetDiameter(node->right, ans);
    ans = max(ans, 1 + leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

void Node::GetMaxWidthPreorder(Node *node, li *count, li level) {
    if(node != NULL) {
        count[level]++;
        GetMaxWidthPreorder(node->left, count, level + 1);
        GetMaxWidthPreorder(node->right, count, level + 1);
    }
}


li Node::GetMaxWidth(Node *node) {
    li height = GetMaxDepth(node);
    li *count = new li[height];
    GetMaxWidthPreorder(node, count, 0);
    return *max_element(count, count + height);
}

bool Node::CheckIdenticalTrees(Node *nodeA, Node *nodeB) {
    if(nodeA == NULL && nodeB == NULL) return true;
    return (nodeA != NULL && nodeB != NULL 
            && nodeA->data == nodeB->data 
            && CheckIdenticalTrees(nodeA->left, nodeB->left) 
            && CheckIdenticalTrees(nodeA->right, nodeB->right)
        );
}

void Node::InorderTraversal(Node *node) {
    if(node != NULL) {
        InorderTraversal(node->left);
        cout << node->data << " ";
        InorderTraversal(node->right);
    }
}

void Node::PreorderTraversal(Node *node) {
    if(node != NULL) {
        cout << node->data << " ";
        PreorderTraversal(node->left);
        PreorderTraversal(node->right);
    }
}

void Node::PostorderTraversal(Node *node) {
    if(node != NULL) {
        PostorderTraversal(node->left);
        PostorderTraversal(node->right);
        cout << node->data << " ";
    }
}

int main() {
    Node *root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->right->right = new Node(8);
    cout << "Size: " << Node::GetSize(root) << endl;
    cout << "Max depth: " << Node::GetMaxDepth(root) << endl;
    li diameter = 0;
    Node::GetDiameter(root, diameter);
    cout << "Diameter: " << diameter << endl;
    cout << "Max Width: " << Node::GetMaxWidth(root) << endl;
    cout << "Identical: " << Node::CheckIdenticalTrees(root, root) << endl;

    Node::InorderTraversal(root); cout << endl;
    Node::PreorderTraversal(root); cout << endl;
    Node::PostorderTraversal(root); cout << endl;
    return 0;
}