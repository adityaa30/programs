#include<bits\stdc++.h>
using namespace std;
int main()
{
	int n,l=0,u=0;
	string s;
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]<='Z')
			u++;
		else if(s[i]>='a')
			l++;
	}
	if(u<=l)
	{for(int i=0;i<n;i++)
		if(s[i]<='Z')
			s[i]=s[i]+32;
	cout<<s<<"\n";
		
	}
	else
	{
	{for(int i=0;i<n;i++)
		if(s[i]>='a')
			s[i]=s[i]-32;
	cout<<s<<"\n";
		
	}
	}
	
}
