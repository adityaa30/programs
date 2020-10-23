#include<bits\stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,sum1=0,sum2=0;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)
		cin>>a[i];
		sort(a.begin(),a.end());
		for(int i=0;i<n;i++)
		{if(a[i]<0)
		sum1-=a[i];
		else
		sum2+=a[i];
		}
		if(sum1==sum2)
		cout<<"NO"<<"\n";
		else if(sum2>sum1)
		{
			sort(a.rbegin(),a.rend());
			cout<<"YES"<<"\n";
			for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
			cout<<"\n";
		}
		else
		{
			cout<<"YES"<<"\n";
			for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
			cout<<"\n";	
		}
	}
}
