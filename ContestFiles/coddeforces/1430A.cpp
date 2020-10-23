#include<bits\stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a=0,b=0,c=0;
		for(int i=0;i<=n/3+1;i++)
		for(int j=0;j<=n/5+1;j++)
		for(int k=0;k<=n/7+1;k++)
		{
			if(i*3+j*5+k*7==n)
			{
				a=i;
				b=j;
				c=k;
				break;
			}
		}
		if((a||b)||c)
		{
			cout<<a<<" "<<b<<" "<<c<<" "<<"\n";
		}
		else
		cout<<-1<<"\n";
	}
}
