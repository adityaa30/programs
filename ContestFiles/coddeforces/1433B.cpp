#include<bits\stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k=0,n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]==1)
			k++;
		}
		if(k==1)
		cout<<0<<"\n";
		else
		{	k=0;
			int i=0,j=0,m=0;
			while(a[i]==0)
			{
				i++;
			}
			k=i;
			for(i=0;i<n;i++)
			{
				if(a[i]==1)
				{
					j=i;
				}
			}
			for(int i=k;i<j;i++)
			{
				if(a[i]==0)
				m++;
			}
			cout<<m<<"\n";
			
		}
		
	}
	
}
