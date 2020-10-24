#include<bits/stdc++.h>
using namespace std;
 
struct node{
	int data;
	node *left, *right;
};

node* newnode(int x){
	node *temp = new node();
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
return temp;	
}
void printPaths(node *root, vector<int> paths, int k, int sum){
	if(root == NULL)
		return;

	paths.push_back(root->data);
	sum+=root->data;

	if(root->left == NULL && root->right == NULL && sum==k){
		for(int i=0; i<paths.size(); i++){
			cout<<paths[i]<<" ";
		}
		cout<<endl;
	}

	printPaths(root->left, paths, k, sum);
	printPaths(root->right, paths, k, sum);
}
void allPaths(node *root, int k){
	std::vector<int> paths;
	int sum=0;
	printPaths(root, paths, k, sum);
}

int main(){
	node *root = newnode(10);
	root->left = newnode(8);  
    root->right = newnode(2);  
    root->left->left = newnode(3);  
    root->left->right = newnode(5);  
    root->right->left = newnode(2);  
    int k=23;
      
    allPaths(root, k);  
    return 0;  
}