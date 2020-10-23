#include<bits\stdc++.h>
using namespace std;
int main()
{
	int a[5][5]={0};
	for(int i=1;i<4;i++)
	for(int j=1;j<4;j++)
	{cin>>a[i][j];
	}
	for(int i=1;i<4;i++)
	{for(int j=1;j<4;j++)
	{	int k=a[i][j]+a[i][j+1]+a[i][j-1]+a[i+1][j]+a[i-1][j];
		if(k%2==0)
		cout<<1;
		else
		cout<<0;
	}
	cout<<"\n";
	}	
	
}
