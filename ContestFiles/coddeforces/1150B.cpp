#include<bits\stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	char a[n][n];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		cin>>a[i][j];
	}
	if(n==3)
	{	if(a[0][0]=='.'||a[2][0]=='.'||a[0][2]=='.'||a[2][2]=='.')
		{
			cout<<"NO";
				return 0;
		}
		if(a[0][0]=='#'&&a[0][1]=='#'&&a[0][2]=='#'&&a[0][1]=='#'&&a[1][1]=='#'&&a[2][1]=='#'&&a[0][2]=='#'&&a[1][2]=='#'&&a[2][2]=='#')
		{
			cout<<"YES";
				return 0;
		}
		if(a[1][0]=='#'||a[1][1]=='#'||a[1][2]=='#'||a[0][1]=='#'||a[2][1]=='#')
		{
			cout<<"NO";
				return 0;
		}
		cout<<"YES";
				return 0;
	}
	for(int i=1;i<n-1;i++)
	for(int j=0;j<n-2;j++)
	{
		if(a[i][j]=='.')
		{
			if(a[i][j+1]=='.'&&a[i-1][j+1]=='.'&&a[i+1][j+1]=='.'&&a[i][j+2]=='.')
			{a[i][j]='#';
			a[i][j+1]='#';
			a[i][j+2]='#';
			a[i-1][j+1]='#';
			a[i+1][j+1]='#';
			}
		
		}
	}
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		if(a[i][j]=='.')
		{
			cout<<"NO";
			return 0;
		
		}
	}
	cout<<"YES";
}
