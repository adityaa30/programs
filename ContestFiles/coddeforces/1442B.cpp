#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		long long b=0;
		cin>>n>>m;
		long a[n][m];
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
		for(int i=0;i<n/2;i++)
		for(int j=0;j<m/2;j++)
		{
			long long k=0;
			k=a[i][j]+a[i][m-1-j]+a[n-1-i][j]+a[n-1-i][m-j-1];
			k=k/4;
			b+=abs(a[i][j]-k)+abs(a[i][m-1-j]-k)+abs(a[n-1-i][j]-k)+abs(a[n-1-i][m-j-1]-k);
			
		}
		if(n%2!=0)
		{for(int j=0;j<m/2;j++)
		{	int i=n/2;
			long long k=0;
			k=a[i][j]+a[i][m-1-j];
			k=k/2;
			b+=abs(a[i][j]-k)+abs(a[i][m-1-j]-k);
			
		}
				
		}
		if(n%2==0&&m%2!=0)
		{for(int i=0;i<n/2;n++)
		{	int j=m/2;
			long long k=0;
			k=a[i][j]+a[n-1-i][j];
			k=k/2;
			b+=abs(a[i][j]-k)+abs(a[n-1-i][j]-k);
			
		}
				
	}
		cout<<b<<"\n";
		
		
	}
}
