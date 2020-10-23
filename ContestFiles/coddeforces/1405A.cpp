#include<bits\stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,l=0,u=0;
		cin>>n;
		vector<long> a(n);
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=n-1;i>=0;i--)cout<<a[i]<<" ";
		cout<<"\n";
	}
 }
