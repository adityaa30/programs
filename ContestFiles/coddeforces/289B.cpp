#include<bits\stdc++.h>
using namespace std;
int main()
{
	int n,m,d;
	long long s1=0,s2=0;
	cin>>n>>m>>d;
	int a[n][m];
	vector<int> b;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		cin>>a[i][j];
		b.push_back(a[i][j]);
		if((a[i][j]-a[0][0])%d!=0)
		{
			cout<<-1;
			return 0;
		}
	}
	sort(b.begin(),b.end());
	if(n*m%2!=0)
	{
		int k=b[n*m/2];
		for(int i=0;i<n*m;i++)
		{
			s1+=(long long)(max(b[i]-k,k-b[i])/d);
		}
		cout<<s1;
	}
	else 
	{
		int k1=b[n*m/2-1],k2=b[n*m/2];
		for(int i=0;i<n*m;i++)
		{
			s1+=(long long)(max(b[i]-k1,k1-b[i])/d);
		}
		for(int i=0;i<n*m;i++)
		{
			s2+=(long long)(max(b[i]-k2,k2-b[i])/d);
		}
		cout<<min(s1,s2);
	}
	
}
