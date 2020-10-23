#include<iostream>
using namespace std ;
int main()
{
	long long int n, m, a;
	cin>>n>>m>>a;
	if(n>a&&m>a&&n%a!=0&&m%a!=0)
	{n=n/a+1;
	m=m/a+1;
	cout<<m*n;}
	else if(n>a&&m>a&&n%a==0&&m%a!=0)
	{n=n/a;
	m=m/a+1;
	cout<<m*n;}
	else if(n>a&&m>a&&n%a!=0&&m%a==0)
	{n=n/a+1;
	m=m/a;
	cout<<m*n;}
	else if(n>a&&m>a&&n%a==0&&m%a==0)
	{n=n/a;
	m=m/a;
	cout<<m*n;}
	else if(n<a&&m>a)
	{m=m/a+1;
	cout<<m;
	}
	else if(n==a&&m>a)
	{m=m/a;
	cout<<m;
	}
	else if(m<a&&n>a)
	{n=n/a+1;
	cout<<n;
	}
	else if(m==a&&n>a)
	{n=n/a;
	cout<<n;
	}
	else
	cout<<1;
}
