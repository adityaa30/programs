#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n,k=0;
		cin>>n>>m;
		while(n--)
		{int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(b==c)
		k++;	
		}
		if(m%2!=0)
		cout<<"NO"<<"\n";
		else if(k==0)
		cout<<"NO"<<"\n";
		else
		cout<<"YES"<<"\n";
	}
}
