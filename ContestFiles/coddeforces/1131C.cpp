#include<bits\stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==2||n==3)
	{
		for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
		cout<<"\n";
	}
	else if(n%2==0)
	{	sort(a,a+n);
		for(int i=0;i<n/2;i++)
	{
		cout<<a[2*i]<<" ";
	}
		for(int i=n/2;i>0;i--)
	{
		cout<<a[2*i-1]<<" ";
	}
		cout<<"\n";
	}
	else
	{
		sort(a,a+n);
	for(int i=0;i<n/2;i++)
	{
		cout<<a[2*i]<<" ";
	}
		cout<<a[n-1]<<" ";
		for(int i=n/2;i>0;i--)
	{
		cout<<a[2*i-1]<<" ";
	}
		cout<<"\n";
	}
}
