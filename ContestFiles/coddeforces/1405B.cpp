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
		vector<long> a(n);
		long long sum1=0,sum2=0,sum=0,diff=0,mi=0;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++)
		{
			
			if(a[i]>0)
			{
				sum1+=a[i];
			}
			if(a[i]<0)
			{
				sum2-=a[i];
			}
			if(sum1<=sum2)
			{
				diff=sum2-sum1;
				if(mi<diff)
				mi=diff;
			}
		}
		cout<<mi<<"\n";
	}
 } 
