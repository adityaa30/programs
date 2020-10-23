#include<bits\stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,y,d=1;
		cin>>n>>x>>y;
		int i=1;
		while(i<n)
		{
			if((y-x)%(n-i)==0)
			{
				d=(y-x)/(n-i);
				break;
			}
			i++;
		}
		int k=x/d;
		for(int j=0;j<=n-i;j++)
		{
			cout<<x+j*d<<" ";
		}
		n-=n-i+1;
		i=1;
		while(n>0&&i<=k)
		{
		cout<<x-i*d<<" ";
		n--;
		i++;
		}
		i=1;
		while(n>0)
		{
		cout<<y+i*d<<" ";
		n--;
		i++;
		}
		cout<<"\n";
		
	}
}
