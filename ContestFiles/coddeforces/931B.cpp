#include<bits\stdc++.h>
using namespace std;
int fn(int,int,int);
int main()
{
	int n,a,b,x=0;
	cin>>n>>a>>b;
	int temp=n;
	if(a>b)
		swap(a,b);
	if(a<=n/2&&b>n/2)
		{
			cout<<"Final!";
			return 0;
		}
	while(true)
	{
		if((a+1==b&&b%2==0)||n==2)
		{	x++;
			break;
		}
		else
		{
			x++;
			a=max(max(a/2,(a+1)/2),1);
			b=max(max(b/2,(b+1)/2),1);
			n=n/2;
		}
	}

		cout<<x;
}


