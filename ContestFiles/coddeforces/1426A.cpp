#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		if(n<3)
		{cout<<1<<"\n";
		}
		else if((n-2)%x==0)
		{
			cout<<(n-2)/x+1<<"\n";
		}
		else 
		{
			cout<<(n-2)/x+2<<"\n";
		}
	}
}
