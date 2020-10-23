#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a=0,p=0;
		cin>>n;
		string s;
		cin>>s;
		for(int i=0;i<n;i++)
			if(s[i]=='P')
			p++;
		a=n-p;
		if(n==1||a==0||p==0)
		{
			cout<<0<<"\n";
		}
		else
		{	if(a==1)
			{
				for(int i=0;i<n;i++)
			{
				if(s[i]=='A')
				{int curra=i;
				cout<<n-1-curra<<"\n";
				}
			}
			}
			else{
			int lasta=0,curra=0,diff=0,maxdiff=0;
			int i=0;
			while(1)
			{
				if(s[i]=='A')
				{
					curra=i;
					lasta=i;
					break;
				}
				i++;
				
			}
			for(i=curra+1;i<n;i++)
			{
				if(s[i]=='A')
				{curra=i;
				diff=curra-lasta-1;
				lasta=i;
				if(maxdiff<=diff)
				{maxdiff=diff;
				}
				
				}
			}
			if(n-lasta-1>=maxdiff)
			{maxdiff=n-lasta-1;
			}
			cout<<maxdiff<<"\n";
			}
			
		}
	}
	
}
