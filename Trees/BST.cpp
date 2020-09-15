#include <bits/stdc++.h>
#define li long long int
using namespace std;

struct Node {
    li data;
    Node *left, *right, *parent;

    Node(li data, Node *parent) {
        this->data = data;
        left = NULL;
        right = NULL;
        this->parent = parent;
    }
};

Node* AddNode(Node *node, li data, Node* prevNode=NULL) {
    if(node == NULL) return new Node(data, prevNode);
    if(data < node->data) node->left = AddNode(node->left, data, node);
    else node->right = AddNode(node->right, data, node);
    return node;
}

Node* FindMiniumumValue(Node *node) {
    if(node->left == NULL) return node;
    else return FindMiniumumValue(node->left);
}

Node* InorderSuccessor(Node *node) {
    Node *ans = NULL;
    if(node->right != NULL) {
        ans = node->right;
        while(ans->left != NULL) ans = ans->left;
    } else {
        ans = node->parent;
        Node *temp = node;
        while(ans != NULL && temp == ans->right) {
            temp = ans;
            ans = ans->parent;
        }
        if(ans == NULL) ans = node; // Given node is root with no children
    }

    return ans;
}

void AddGreatorValues(Node *node, li& sum) {
    if(node == NULL) return;

    AddGreatorValues(node->right, sum);
    sum += node->data;
    node->data = sum;
    AddGreatorValues(node->left, sum);


    return;
}

Node* LCA(Node *node, li n1, li n2) { // Confirmed that n1 < n2
    if(node == NULL) return NULL;
    else if(n1 <= node->data && node->data <= n2) return node;
    else if(node->data > n2) return LCA(node->left , n1, n2);
    else /* (node->data < n1) */ return LCA(node->right, n1, n2);
}

void LevelOrderTraversal(Node *node) {
    queue<Node*> q;
    q.push(node);
    Node *temp = NULL;
    while(!q.empty()) {
        temp = q.front();
        q.pop();

        cout << temp->data << ' ';
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
    cout << endl;
}

void GreaterKeys(Node *node, li& currentSum) {
    if(node == NULL) return;
    GreaterKeys(node->right, currentSum);
    node->data = node->data + currentSum;
    currentSum = node->data;
    GreaterKeys(node->left, currentSum);
}



int main() {
    Node *root = new Node(50, NULL);
    AddNode(root, 30);
    AddNode(root, 70);
    AddNode(root, 20);
    AddNode(root, 40);
    AddNode(root, 60);
    AddNode(root, 80);

    LevelOrderTraversal(root);
    li temp = 0;
    GreaterKeys(root, temp);
    LevelOrderTraversal(root);
    // LevelOrderTraversal(root);
    // cout << "LCA of 60 & 70: " << LCA(root, 60, 70)->data << endl;
    // cout << "Minimum: " << FindMiniumumValue(root)->data << endl;
    // cout << "Inorder Successor of 60: " << InorderSuccessor(root->right->left)->data << endl;
    // li sum = 0;
    // AddGreatorValues(root, sum);
    // LevelOrderTraversal(root); cout << endl;

    return 0;
}