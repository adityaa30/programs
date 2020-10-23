#include<bits\stdc++.h>
#include<vector>
using namespace std;
int main()
{
	int n,count=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	vector<int> v;
	for(int i=0;i<n-1;i++)
	{
		if(a[i]!=a[i+1])
		{	count++;
			v.push_back(a[i+1]-a[i]);
		}
		
	}
	if(count>2)
	{
		cout<<-1;
	}
	else if(count==0)
	{
		cout<<0<<"\n";
	}
	else if(count==1)
	{
		if(v[0]%2==0)
		{
			cout<<v[0]/2<<"\n";
		}
		else
		{
			cout<<v[0]<<"\n";
		}
	}
	else if(v[0]!=v[1])
	{
		cout<<-1;
	}
	else
	{
		cout<<v[0]<<"\n";
	}
	
}
