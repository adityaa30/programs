#include<bits\stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n=s.size(),count=0;
	if(n==1)
	{
		cout<<0;
	}
	else
	{	long sum=0;
		for(int i=0;i<n;i++)
		{
			sum+=(int)(s[i]-'0');
		}
		count++;
		if(sum<10)
		{
			cout<<1;
			return 0;
		}
		while(sum>9)
		{	long a=sum;
			sum=0;
			while(a>0)
			{
				sum+=a%10;
				a=a/10;
			}
			count++;
			
		}
		cout<<count;
	}
	
	
}
