#include<bits\stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,count=0;
		cin>>n;
		vector<string> s(n);
		for(int i=0;i<n;i++)cin>>s[i];
		int a[26]={0};
		for(int i=0;i<n;i++)
		{for(int j=0;j<s[i].size();j++)
		{
			a[s[i][j]-'a']++;
		}
		}
		for(int i=0;i<26;i++)
		{
			if(a[i]%n==0)
				count++;
		}
		if(count==26)
		{
			cout<<"YES"<<"\n";
		}
		else
			cout<<"NO"<<"\n";
	}
}
