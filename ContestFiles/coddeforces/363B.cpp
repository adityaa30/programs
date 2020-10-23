#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	long best=0,curr=0,x=0;
	for(int i=0;i<k;i++)
	{
		curr+=v[i];
	}
	best=curr;
	for(int i=1;i<=n-k;i++)
	{
		curr=curr-v[i-1]+v[i+k-1];
		if(curr<best)
		{
			best=curr;
			x=i;
		}
		
	}
	cout<<x+1;
}
