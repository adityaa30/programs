#include<iostream>
using namespace std;
int main()
{
	int s=0,n;
	cin>>n;
	for(int i=0; i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b+c>1)
			s++;
		
	}
	cout<<s;
}
