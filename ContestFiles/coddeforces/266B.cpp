#include<bits\stdc++.h>
using namespace std;
int main()
{
	int n,t;
	cin>>n>>t;
	string s;
	cin>>s;
	while(t--)
	{
		for(int j=0;j<n-1;j++)
		{
			if(s[j]=='B'&&s[j+1]=='G')
			{s[j]='G',s[j+1]='B',j++;}
		}
	}
	cout<<s;
}
