#include<bits/stdc++.h>
using namespace std;

struct Lnode
{
	int data;
	Lnode* next;
};

struct Tnode
{
	int data;
	Tnode *left, *right;
};

Lnode* newnode(int x){
	Lnode *temp = new Lnode();
	temp->next = NULL;
	temp->data =x;
    return temp;
}

Tnode* newTnode(int x){
	Tnode *temp = new Tnode();
	temp->data  = x;
	temp->left = temp->right = NULL;
    return temp;
}

Lnode* insert(Lnode *head, int x){
	if(head == NULL){
		Lnode *temp = newnode(x);
		head = temp;
	}
	else{
		Lnode *temp = newnode(x);
		temp->next = head;
		head = temp;
	}
	return head;
}

void inorder(Tnode* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void printLL(Lnode *head){
	Lnode *temp = head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int countNodes(Lnode* head){
	Lnode *temp = head;
	int count=0;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	return count;
}

Tnode* LTBrec(Lnode **head, int n){
	if(n<=0)
		return NULL;

	Tnode *left = LTBrec(head , n/2);

	Tnode *root = newTnode((*head)->data);
	root->left = left;
	*head = (*head)->next;

	root->right = LTBrec(head, n-n/2-1);

	return root;

}

Tnode* LLtoBST(Lnode *head){
	int n = countNodes(head);
	return LTBrec(&head, n);
} 

int main(){
	Lnode *head = NULL;
	head = insert(head, 7);
	head = insert(head, 6);
	head = insert(head, 5);
	head = insert(head, 4);
	head = insert(head, 3);
	head = insert(head, 2);
	head = insert(head, 1);

	printLL(head);

	Tnode* root = LLtoBST(head);

	inorder(root);

return 0;	
}