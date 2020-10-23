#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,b,a;
	cin>>n>>b>>a;
	int s[n];
	for(int i=0;i<n;i++)
		cin>>s[i];
	int ans=0,max=a;
	if(a+b>=n)
	{
		cout<<n;

	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(s[i]==0)
			{	if(a>0)
				{
				a--;
				ans++;}
				else if(b>0)
				{
					b--;
					ans++;
				}
				else 
				{
				
					cout<<ans;
					return 0;
				}
			}
			else
			{	if(a==0&&b==0)
				{
					
					cout<<ans;
					return 0;
				}
				else if(a==max||b==0)
				{
					a--;
					ans++;
				}
				
				else if(a<max&&b==0)
				{
					a--;
					ans++;
				}
				else if(a<max&&b>0)
				{
					b--;
					a++;
					ans++;
				}
				
			}
		}
		cout<<n;
	}
	
}
