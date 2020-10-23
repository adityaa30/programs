#include<bits\stdc++.h>
using namespace std;
int main()
{
	long long int n,x;
	cin>>n>>x;
	vector<long long> v(n);
	for(long long i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	unsigned long long sum=0;
	for(long long i=0;i<n;i++)
	{	if(x>1)
		{	sum+=v[i]*x;
		x--;}
		else
		{
			sum+=v[i];
		}
	}
	cout<<sum;
}

