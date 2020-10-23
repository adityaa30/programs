#include<bits\stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long n,k=1,m=0;
		cin>>n;
		vector<long> a(n);
		for(long i=0;i<n;i++)
		cin>>a[i];
		if(a[0]==1)
		m++;
		while(k<n)
		{if(a[k]==1&&k<n-2)
		{	long l=k;
			while(a[l]==1&&l<n)
			l++;
			m+=(l-k)/3;	
			k=l;
		}
		k++;
		}
		cout<<m<<"\n";
		
	}
}
