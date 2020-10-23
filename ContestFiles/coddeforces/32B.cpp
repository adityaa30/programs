#include<bits\stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{	if(s[i]=='.')
		{
			cout<<0;
		}
		else if(s[i]=='-'&&s[i+1]=='-')
		{
			cout<<2;
			i++;
		}
		else if(s[i]=='-'&&s[i+1]=='.')
		{
			cout<<1;
			i++;
		}
	}
	cout<<"\n";
}
