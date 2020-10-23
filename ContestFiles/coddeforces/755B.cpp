#include<bits\stdc++.h>
using namespace std;
int main()
{
	int m,n,count=0;
	cin>>m>>n;
	int t=m+n;
	string s;
	vector<string> p,e;
	if(m>n)
	{	for(int i=0;i<m;i++)
			{
			cin>>s;
			p.push_back(s);}
		for(int i=0;i<n;i++)
			{
			cin>>s;
			e.push_back(s);}
		cout<<"YES"<<"\n";
	}
	else if(m<n)
	{	for(int i=0;i<m;i++)
			{
			cin>>s;
			p.push_back(s);}
		for(int i=0;i<n;i++)
			{
			cin>>s;
			e.push_back(s);}
		cout<<"NO"<<"\n";
	}
	else
	{	for(int i=0;i<m;i++)
			{
			cin>>s;
			p.push_back(s);}
		for(int i=0;i<n;i++)
			{
			cin>>s;
			e.push_back(s);}
		for(int i=0;i<m;i++)
			{for(int j=0;j<n;j++)
				if(p[i]==e[j])
				{count++;
				}
			}
		t=t-count;
		if(t%2==0)
		{
			cout<<"NO"<<"\n";
		}
		else
		{
			cout<<"YES"<<"\n";
		}
	}
	
}
