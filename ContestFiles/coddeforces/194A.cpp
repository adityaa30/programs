#include<bits\stdc++.h>
using namespace std;
int main()
{
	int n,k=0;
	cin>>n>>k;
	int a=k-2*n;
	if(a>=n)
		cout<<0;
	else
		cout<<n-a;
	
}
