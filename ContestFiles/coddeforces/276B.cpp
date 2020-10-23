#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n=s.size(),count=0;
	int a[26]={0};
	for(int i=0;i<n;i++)
	{
		a[s[i]-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		if(a[i]%2!=0)
		{
			count++;
		}	
	}
	if(count<2||count%2!=0)
	{cout<<"First";
	}
	else
		cout<<"Second";
}
