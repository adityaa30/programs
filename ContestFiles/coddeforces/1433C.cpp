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
		vector<int> a(n),b(n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			b[i]=a[i];
		}
		sort(a.begin(),a.end());
		if(a[0]==a[n-1])
		{
			cout<<-1<<"\n";
		}
		else
		{	if(b[0]==a[n-1]&&b[0]==b[1])
			{
				for(int i=0;i<n;i++)
			{
				if(b[i]!=b[i+1])
				{
					cout<<i+1<<"\n";
					break;
				}
			}
				
			}
			else
			for(int i=0;i<n;i++)
			{
				if(b[i]==a[n-1])
				{
					cout<<i+1<<"\n";
					break;
				}
			}
		}
		
	}
	
}
