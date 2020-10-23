#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b,c,d;
		cin>>a>>b>>c;
		if(a>b)
		swap(a,b);
		if(b>c)
		swap(b,c);
		cout<<(a+c-b)<<"\n";
		
	}
}
