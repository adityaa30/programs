#include<bits\stdc++.h>
using namespace std;
int main()
{
	int n,m,count=0;
	cin>>n>>m;
	char a[n][m];
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		cin>>a[i][j];
	}
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		if(a[i][j]=='W')
		{
			if(a[i][min(j+1,m-1)]=='P'||a[min(i+1,n-1)][j]=='P'||a[max(0,i-1)][j]=='P'||a[i][max(j-1,0)]=='P')
			{count++;
			}
		
		}
	}
	cout<<count;
}
