#include<bits\stdc++.h>
using namespace std;
int main()
{
	int n,a=0,k=0;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		if(v[i]==5)
			a++;
	}
	k=n-a;
	if(a==n)
	{
		cout<<-1;
	}
	else if(a<9)
	{
		cout<<0;
	}
	else
	{
		a=a/9;
		for(int i=0;i<a*9;i++)
		cout<<5;
		for(int i=0;i<k;i++)
		cout<<0;
		cout<<"\n";
	}
}
