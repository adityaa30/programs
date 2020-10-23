#include<bits\stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long x;
		cin>>x;
		long long sum=0;
		int k=x%10,m=1;
		while(x)
		{m++;
		x=x/10;
		}
		sum=10*(k-1)+m*(m-1)/2;
		cout<<sum<<"\n";
	}
	
}
