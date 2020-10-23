#include<iostream>
#include<iomanip>
using namespace std;
void sort(int n,int a[])
{	int k;
	for(int i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
		{
			k=a[i];
			a[i]=a[i+1];
			a[i+1]=k;
		}
	}
}
int main()
{
	int n,l,m=0;
	cin>>n>>l;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(n,a);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	int b[n-1];
	for(int i=0;i<n;i++)
	{
		b[i]=a[i+1]-a[i];
		
	}
	float c=b[0];
	for(int i=0;i<n-1;i++)
	{	if(b[i]>c){
		m=i;
		c=b[i];
	}
		
	}
	cout<<fixed<<setprecision(9)<<c/2<<"\n";
}

