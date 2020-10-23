#include <bits/stdc++.h>
using namespace std;
int main() 
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int k,n,one=0 ,two=0 ,more=0;
		long long sum=0;
		cin>>n>>k;
		int a[n],w[k];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<k;i++)
		{
			cin>>w[i];
		}
		sort(a,a+n);
		sort(w,w+k);
		for(int i=0;i<k;i++)
		{
			if(w[i]==1)
				{one++;
				w[i]=0;}
			else if(w[i]==2)
				{two++;
				w[i]=0;}
			else
				{w[i]--;
				}
		}
		more=k-one-two;
		int b=k+two;
		for(int i=1;i<one+1;i++)
		{
			sum=sum+(long long) 2*a[n-i];
		}
		for(int i=one+1;i<2*two+1+one;i++)
		{
			sum=sum+(long long) a[n-i];
		}
		for(int i=2*two+one+1;i<b+1;i++)
		{
			sum=sum+(long long) a[n-i];
		}
		b=0;
		for(int i=k-1;i>=k-more;i--)
		{	
			sum=sum+(long long) a[b];
			b+=w[i];
		}
		cout<<sum<<"\n";
		
	}}
