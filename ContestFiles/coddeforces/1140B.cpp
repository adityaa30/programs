#include<bits\stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int k1=n,k2=-1;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='>')
			{k1=i;
			break;
			}
		}
		for(int i=n-1;i>=0;i--)
		{
			if(s[i]=='<')
			{k2=i;
			break;
			}
		}
		if(k1==0||k2==n-1||k1==n||k2==-1)
		{
			cout<<0<<"\n";
		}
		else if(k1>k2)
		{
			cout<<min(k2+1,n-k1)<<"\n";
		}
		else
		{
			cout<<min(k1,n-k2-1)<<"\n";
		}
	}
}

