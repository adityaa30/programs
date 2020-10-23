#include<bits\stdc++.h>
using namespace std;
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		long long n,m,sum=0;
		cin>>n>>m;
		long long k=n/m;
		long long p=k/10;
		int d=k%10;
		m=m%10;
		for(int i=1;i<10;i++)
		{
			sum+=(m*i)%10;
		}
		sum=sum*p;
		for(int i=1;i<=d;i++)
		sum+=(m*i)%10;
		cout<<sum<<"\n";
	}
}
