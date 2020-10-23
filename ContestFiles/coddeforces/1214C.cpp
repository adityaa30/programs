#include<bits\stdc++.h>

using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	if(n%2==1)
	{	cout<<"NO";
		return 0;
	}
	else
	{	int count=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='(')
				count++;
		}
		if(count!=n/2)
		{
			cout<<"NO";
			return 0;
		}
		else
		{
			if(n==2)
			{
				cout<<"YES";
				return 0;
			}
			else 
			{
				int open=0,close=0;
				int i=0;
				for(i=0;i<n;i++)
				{
					if(s[i]=='(')
						open++;
					if(s[i]==')')
						close++;
					if(open-close==-1)
					{
						break;
					}
				}
				if(i==n)
				{
					cout<<"YES";
					return 0;
				}
				s.erase(s.begin()+i);
				s.push_back('(');
				open=0,close=0;
				for(i=0;i<n;i++)
				{
					if(s[i]=='(')
						open++;
					if(s[i]==')')
						close++;
					if(open-close==-1)
					{
						cout<<"NO";
						return 0;
					}
				}
				cout<<"YES";
			}
		}
		
	}
}
