#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long n,a,k;
		cin>>n;
		a=(int)sqrt(n+1);
		k=min((n-a)/(a+1)+a,(n-a-1)/a+a-1);
		cout<<k+1<<"\n";
	}
}
