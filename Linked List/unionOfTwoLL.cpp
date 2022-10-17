// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* makeUnion(struct Node* head1, struct Node* head2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        printList(makeUnion(first,second));
    }
    return 0;
}
// } Driver Code Ends


/*
// structure of the node is as follows

struct node
{
	int data;
	struct node* next;
	
	node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/

struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    set <int> S1,S2;
    Node* temp = head1;
    while(temp){
        S1.insert(temp->data);
        temp = temp->next;
    }
    temp = head2;
    while(temp){
        S2.insert(temp->data);
        temp = temp->next;
    }
    set <int> S3;
    set_union(S1.begin(),S1.end(),S2.begin(),S2.end(),inserter(S3, S3.begin()));
    Node* ans = NULL;
    for(auto i:S3){
        Node* nnode = new Node(i);
        if(ans==NULL){
            ans = nnode;
        }else{
            temp->next = nnode;
        }
        temp = nnode;
    }
    return ans;
    // code here
}
