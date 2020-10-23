#include<bits\stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,zero=0;
		cin>>n>>k;
		long long b=0;
		vector<long> a(n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]==0)
			zero++;
			b+=a[i];
		}
		sort(a.rbegin(),a.rend());
		if(k>=n-zero-1)
		cout<<b<<"\n";
		else
		{
			b=0;
			for(int i=0;i<k+1;i++)
			{
				b+=a[i];
			}
			cout<<b<<"\n";
			
		}
	}
}
