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

// Bottom-up and Top-Down approach
void MirrorTreeRecursive(Node *node) {
    if(node == NULL) return;

    swap(node->left, node->right);
    MirrorTreeRecursive(node->left);
    MirrorTreeRecursive(node->right);

}

void MirrorTreeIterative(Node *node) {
    queue<Node*> q;
    q.push(node);
    
    Node *temp = NULL;
    while(!q.empty()) {
        temp = q.front();
        q.pop();

        swap(temp->left, temp->right);
        
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
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
    MirrorTreeRecursive(root);
    LevelOrderTraversal(root);
    MirrorTreeIterative(root);
    LevelOrderTraversal(root);
}