#include<bits\stdc++.h>
using namespace std;
int main()
{
	int n,i=0,s=0,e=0;
	cin>>n;
	vector<long> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	vector<long> b(a);
	sort(b.begin(),b.end());
	if(b==a)
	{
		cout<<"yes"<<"\n";
		cout<<1<<" "<<1;
		return 0;
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(a[i]!=b[i])
			{
				s=i;
				break;
			}
		}
		for(i=s+1;i<n;i++)
		{
			if(a[i]!=b[i])
			{
				e=i;
			}
		}
		for(i=0;i<=(e-s)/2;i++)
		{
			swap(a[s+i],a[e-i]);
		}
	}
	if(b==a)
	{
		cout<<"yes"<<"\n";
		cout<<s+1<<" "<<e+1;
		return 0;
	}
	else
	{
		cout<<"no";
	}
}
