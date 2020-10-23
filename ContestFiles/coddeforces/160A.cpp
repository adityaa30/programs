#include<iostream>
using namespace std;
int main()
{
	int n,sum=0,b=0;
	cin>>n;
	int k=n;
	int a[n];
	for(int i=0; i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0; i<n;i++){
		sum+=a[i];
	}
	
	for(int j=0;j<n;j++)
	for(int i=0;i<n;i++)
	{
		if(a[i]>a[i+1])
		{
			b=a[i];
			a[i]=a[i+1];
			a[i+1]=b;
			
		}
	}
	if(sum%2==0)
	{
		sum=sum/2;
	while(sum>=0)
	{
		sum=sum-a[k-1];
		k--;	
	}
}
	else{
		sum=sum/2;
		while(sum>0)
	{
		sum=sum-a[k-1];
		k--;	
	}

	}
		cout<<n-k;
 } 
