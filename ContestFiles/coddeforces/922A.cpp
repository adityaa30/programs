#include<bits/stdc++.h>
using namespace std;
int main()
{
	long int a,b;
	cin>>a>>b;
	if(a<b-1||a==b||b==0||(b==1&&a>0))
	{cout<<"NO";
	}
	else if(a%2+b%2==1)
	{
		cout<<"YES"<<"\n";
	}
	else{
		cout<<"NO";
	}
}
