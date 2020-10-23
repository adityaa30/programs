#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	long long x,y,k;
	cin>>x>>y>>k;
	long long m;
	m=k*y+k;
	m=m-1;
	if(m%(x-1)==0)
	m=m/(x-1);
	else
	m=m/(x-1)+1;
	m=m+k;
	cout<<m<<"\n";	}
}
