#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,one=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		{cin>>a[i];
		if(a[i]==1)
			one++;
		}
	int two=n-one;
	if(two==0)
	{for(int i=0;i<n;i++)
		{cout<<1<<" ";
		}
	}
	else if(one==0)
	{
		for(int i=0;i<n;i++)
		{cout<<2<<" ";
		}
	}	
	else
	{
		cout<<2<<" ";
		cout<<1<<" ";
		for(int i=0;i<two-1;i++)
		{cout<<2<<" ";
		}
		for(int i=0;i<one-1;i++)
		{cout<<1<<" ";
		}
	}
}
