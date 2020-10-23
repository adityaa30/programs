#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int t=a+b+c;
	if(t==0)
		{cout<<"0";
		return 0;
	}
	if(c==0&&t!=0)
	{	if(a>b)
			cout<<"+";
		if(a<b)
			cout<<"-";
		if(a==b)
			cout<<"0";
	}
	else
	{
		if(a>t/2)
			cout<<"+";
		else if(b>t/2)
				cout<<"-";
		else
			cout<<"?";
	}
	
	
}
