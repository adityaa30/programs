#include<bits\stdc++.h>
using namespace std;
int main()
{
	int n,k,x=0,y=0,sum1=0,sum2=0;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	for(int i=0;i<n;i++)
	{
		if(v[i]==1)
			x++;
		if(v[i]==2)
			y++;
	}
	if(x<=y)
	{	int a=0;
		for(int i=0;i<n/k;i++)
		for(int j=0;j<k;j++)
		{
			if(v[i*k+j]==1)
			{
				a+=j;
			}
		}
		a=a*k/n;
		for(int i=0;i<n/k;i++)
		for(int j=0;j<k;j++)
		{
			if(v[i*k+j]==1)
			{	if(j>a)
				sum1+=j-a;
				if(j<a)
				sum1+=a-j;
			}
		}
		for(int i=0;i<n/k;i++)
		for(int j=0;j<k;j++)
		{
			if(v[i*k+j]==1)
			{	if(j>a)
				sum2+=j-a-1;
				if(j<a)
				sum2+=a+1-j;
			}
		}
		if(sum1>=sum2&&sum2>0)
		cout<<sum2+1;
		else if(sum1<sum2&&sum1>0)
		cout<<sum1+1;
		else
		cout<<0;
	}
		else
	{	int a=0;
		for(int i=0;i<n/k;i++)
		for(int j=0;j<k;j++)
		{
			if(v[i*k+j]==2)
			{
				a+=j;
			}
		}
		a=a*k/n;
		for(int i=0;i<n/k;i++)
		for(int j=0;j<k;j++)
		{
			if(v[i*k+j]==2)
			{	if(j>a)
				sum1+=j-a;
				if(j<a)
				sum1+=a-j;
			}
		}
		for(int i=0;i<n/k;i++)
		for(int j=0;j<k;j++)
		{
			if(v[i*k+j]==2)
			{	if(j>a)
				sum2+=j-a-1;
				if(j<a)
				sum2+=a+1-j;
			}
		}
		if(sum1>=sum2&&sum2>0)
		cout<<sum2+1;
		else if(sum1<sum2&&sum1>0)
		cout<<sum1+1;
		else
		cout<<0;
	}
}
