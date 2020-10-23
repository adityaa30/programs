#include<iostream>
using namespace std;
int main()
{
	int t,n,k,b,i;
	cin>>t;
	
	for(i=0;i<t;i++)
	{
		cin>>n>>k;
	if(k>n)
	{
	b=k-n;
    }
    else if((n+k)%2!=0)
    {
    	b=1;
	}
    else if(n==k)
    {
    	b=0;
	}
	else{
		b=0;
	}
 
		cout<<b<<"\n";
    }
}
