#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int a,b,n,count=0;
		cin>>a>>b>>n;
		if(a<b)
		{
			while(a<=n&&b<=n)
			{a+=b;
			count++;
			if(a<=n)
			{b+=a;
			count++;
			}
				
			}
			
		}
		else
		{
			while(a<=n&&b<=n)
			{b+=a;
			count++;
			if(b<=n)
			{a+=b;
			count++;
			}
			}
		}
	cout<<count<<"\n";
}}
