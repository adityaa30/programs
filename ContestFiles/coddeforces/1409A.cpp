#include<bits\stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long a,b;
		cin>>a>>b;
		if(a>b)
		{
			swap(a,b);
		}
		long k=0;
		k=(b-a)/10;
		if((b-a)%10)
		{
			k++;
		}
		cout<<k<<"\n";
	}
}
