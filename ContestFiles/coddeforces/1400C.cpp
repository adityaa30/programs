#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int x,k=0,n=s.size();
		cin>>x;
		string w;
		for(int i=0;i<n;i++)
			w.push_back('2');
		
		for(int i=0;i<n;i++)
		{
			if(s[i]=='1')
			{
				if(i>=x&&i<=n-1-x)
				{
					w[i-x]='1';
					w[i+x]='1';
				}
				else if(i<x)
				{
					w[i+x]='1';
				}
				else{
					w[i-x]='1';
				}
			}
			else{
				if(i>=x&&i<=n-1-x)
				{
					w[i-x]='0';
					w[i+x]='0';
				}
				else if(i<x)
				{
					w[i+x]='0';
				}
				else{
					w[i-x]='0';
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			if(w[i]=='2')
				{k=1;
				cout<<-1<<"\n";
				break;}
		}
		if(k==0)
		cout<<w<<"\n";
	}
 } 
