#include<bits\stdc++.h>
using namespace std;
int main()
{
	int n,m,k,count=0;
	cin>>n>>m>>k;
	char a[n][m];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{if(a[i][j]=='.')
		{if(a[min(i+1,m-1)][j]=='.')
			count++;
		 if(a[i][min(j+1,n-1)]=='.')
		 	count++;
		}
	}
	cout<<count;
}
