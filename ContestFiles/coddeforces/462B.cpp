#include<bits\stdc++.h>
using namespace std;
int main()
{
	long long sum=0,k,n;
	cin>>n>>k;
	string s;
	cin>>s;
	long long a[26]={0};
	for(int i=0;i<n;i++)
	{
		a[s[i]-'A']++;
	}
	sort(a,a+26, greater<long>());
	for(int i=0;i<26;i++)
	{
		if(k<=a[i])
		{
			sum+=k*k;
			break;
		}
		else 
		{
			sum+=a[i]*a[i];
			k=k-a[i];
		}
	}
	cout<<sum;
}
