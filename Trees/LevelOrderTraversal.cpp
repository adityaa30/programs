#include <bits/stdc++.h>
#define li long long int
using namespace std;

struct Node {
    li data;
    Node *right, *left, *next;

    Node(li _data) {
        data = _data;
        right = NULL;
        left = NULL;
        next = NULL;
    }

    static void LevelOrderTraversalWithSpace(Node *node, bool printNext);
    static void ConnectSameLevelNodesWithSpace(Node *node);
    static li DifferenceOddEvenLevelNodes1(Node *node);
    static li DifferenceOddEvenLevelNodes2(Node *node);
};

void Node::LevelOrderTraversalWithSpace(Node *node, bool printNext=false) {
    if(node == NULL) return;
    queue<Node*> q;
    
    q.push(node);
    while(!q.empty()) {
        Node *currNode = q.front();
        if(printNext) {
            cout << (currNode->next ? currNode->next->data : -1) << " ";
        } else {
            cout << currNode->data << " ";
        }
        q.pop();

        if(currNode->left != NULL) q.push(currNode->left);
        if(currNode->right != NULL) q.push(currNode->right);
    }
    cout << endl;
}


void Node::ConnectSameLevelNodesWithSpace(Node *node) {
    queue<Node*> q;
    q.push(node);
    q.push(NULL);
    Node *temp = NULL;

    while(!q.empty()) {
        temp = q.front();
        q.pop();

        if(temp != NULL) {
            temp->next = q.front();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        } else if(!q.empty()) {
            q.push(NULL);
        }
    }
}

li Node::DifferenceOddEvenLevelNodes1(Node *node) {
    queue<Node*> q;
    q.push(node);

    Node *temp = NULL;
    li sumEven = 0, sumOdd = 0;
    bool even = true;
    while(!q.empty()) {
        li size = q.size();

        while(size--) {
            temp = q.front();
            q.pop();

            if(even) sumEven += temp->data;
            else sumOdd += temp->data;
        
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
        even = !even;
    }

    return sumEven - sumOdd;
}

li Node::DifferenceOddEvenLevelNodes2(Node* node) {
    if(node == NULL) return 0;
    return node->data
            - DifferenceOddEvenLevelNodes2(node->left)
            - DifferenceOddEvenLevelNodes2(node->right);
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

    Node::ConnectSameLevelNodesWithSpace(root);
    Node::LevelOrderTraversalWithSpace(root);
    Node::LevelOrderTraversalWithSpace(root, true);

    cout << "Difference between odd & even levels: " << Node::DifferenceOddEvenLevelNodes1(root) << endl;
    cout << "Difference between odd & even levels: " << Node::DifferenceOddEvenLevelNodes2(root) << endl;
    return 0;
}