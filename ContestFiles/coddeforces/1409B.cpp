#include<bits\stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b,x,y,n;
		cin>>a>>b>>x>>y>>n;
		if(n>=(a-x+b-y))
		{
			cout<<x*y<<"\n";
		}
		else
		{
			if(x>y)
			{
				swap(x,y);
				swap(a,b);
			}
			if(n<=(a-x)&&n<=(b-y))
			{		if(a>b)
			{
				swap(x,y);
				swap(a,b);
			}
				a=a-n;
				n-=n;
			}
			else if(n<=(a-x)&&n>(b-y))
			{	if((a-n)>(y))
				{	n=n-b+y;
					b=y;
					a=a-n;
				}
				else
				{
				a=a-n;
				n-=n;}
			}
			else
			{
			
				n-=(a-x);
				a=x;
				b=b-n;
				n-=n;
			}
			cout<<a*b<<"\n";
		}
		
	}
}
