#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int m=-1,k=-1,one=0;
		string s;
		cin>>s;
		for(int j=0;j<n;j++)
		{
			if(s[j]=='0')
			{
				m=j;
			}
			
		}
		for(int j=0;j<n;j++)
		{
			if(s[j]=='1')
			{
				k=j;
				break;
			}
		}
		if(k==-1||m<k)
		{
			cout<<s<<"\n";
		}
		else if(m==n-1&&k==0)
		{
			cout<<'0'<<"\n";
		}
		else if(m>k){
		
		for(int j=0;j<k+1;j++)
		{
			cout<<'0';
		}
		for(int j=m+1;j<n;j++)
		{
			cout<<'1';
		}
		cout<<"\n";
			}	
	}
}
