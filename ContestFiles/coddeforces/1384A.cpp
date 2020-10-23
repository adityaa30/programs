#include<bits\stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)cin>>a[i];
		string s;
		for(int i=0;i<a[0];i++)
		s.push_back('a');
		cout<<s;
		cout<<"\n";
		for(int i=0;i<n-1;i++)
		{
			if(a[i]>=a[i+1])
			{
				cout<<s;
				cout<<"\n";
				s.erase(s.begin()+a[i+1],s.begin()+a[i]);
			}
			else
			{	char b=s[s.size()-1];
					if(b=='z')
						b='a';
					else 
						b++;
				for(int j=0;j<a[i+1]-a[i];j++)
				s.push_back('a');
				cout<<s;
				cout<<"\n";
			}
		}
		cout<<s;
		cout<<"\n";
	}
}

