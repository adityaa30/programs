#include<bits\stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long n,k,a=0,b=0;
		cin>>n>>k;
		string s;
		cin>>s;
		for(int i=0;i<k;i++)
		{
			if(s[i]=='0')
			a++;
			else if(s[i]=='1')
			b++;
		}
		if(a>k/2||b>k/2)
		{
			cout<<"NO"<<"\n";}
		else
		{	long m=0;
			for(int i=0;i<n-k;i++)
		{
			if(s[i]==s[k+i])
			{
				m++;
			}
			else if(s[i]!=s[k+i]&&(s[i]!='?'&&s[k+i]=='?'))
			{
				m++;
				s[k+i]=s[i];	
			}
			else if(s[i]!=s[k+i]&&(s[i]=='?'&&s[k+i]!='?'))
			{
				m++;
				s[i]=s[k+i];	
			}
			

		}
		if(m==n-k)
		{
			cout<<"YES"<<"\n";
		}
		else
		{
			cout<<"NO"<<"\n";
		}
			
		}
	}
 }
