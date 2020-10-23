#include<bits\stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long m=0;
		int n;
		cin>>n;
		vector<int> a(n),l(n),b,c(n);
		for(int i=0;i<n;i++)
		cin>>a[i];
		for(int i=0;i<n;i++)
		cin>>l[i];
		for(int i=0;i<n;i++)
		{
			if(l[i]==0)
			b.push_back(a[i]);
		}
		sort(b.rbegin(),b.rend());
		int j=0;
		for(int i=0;i<n;i++)
		{
		if(l[i]==0)
		{
			c[i]=b[j];
			j++;
		}
		else
		{
			c[i]=a[i];
			
		}
		
			
		}
		for(int i=0;i<n;i++)
		cout<<c[i]<<" ";
		cout<<"\n";
	}
}
