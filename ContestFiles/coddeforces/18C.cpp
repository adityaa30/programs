#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=a[i];
	if(sum%2==1||sum%2==-1)
	{
		cout<<0;
	}
	else
	{	if(sum!=0){
		sum=sum/2;
		int sumk=0;
		int i=0,count=0;
		while(i<n)
		{
			sumk+=a[i];
			if(sum==sumk)
				count++;
			i++;
		}
		
			cout<<count;
		}
	
		else{
			int sum=0;
			int i=0,count=0;
		while(i<n)
		{	
			sum+=a[i];
			if(sum==0)
				count++;
			i++;
		}
			cout<<count-1;
		}
	}
}
