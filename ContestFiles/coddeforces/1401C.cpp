#include <bits\stdc++.h>
using namespace std;
int gcd(int,int);
int main()
{ int t;
cin>>t;
while(t--)
{
	int n;
	cin>>n;
	long a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long m=a[0];
	for(int i=0;i<n;i++)
	{
		m=min(a[i],m);
	}
	long b[n];
	for(int i=0;i<n;i++)
	{
		b[i]=a[i];
	}
	sort(b,b+n);
	int j=0;
	for(j=0;j<n;j++)
	{
		if(a[j]!=b[j])
		{	if(m!=gcd(a[j],b[j]))
			{cout<<"NO"<<"\n";
			j==-1;
			break;}
		}
		
	}
	if(j==n)
	{
		cout<<"yes"<<"\n";
	}
	
	
}

    
   

}
int gcd(int n1, int n2)
{
	 while(n1 != n2)
    {
        if(n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }
    return n1;
	
}
