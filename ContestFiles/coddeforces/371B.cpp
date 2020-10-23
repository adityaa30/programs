#include<bits\stdc++.h>
using namespace std;
int check(int,int []);
int main()
{
	int a,b;
	int v[2][3]={0};
	cin>>a>>b;
	int x=check(a,v[0]);
	int y=check(b,v[1]);
	if(x==y||(x==1&&y==1))
	{
		int k=0;
		for(int j=0;j<3;j++)
			{
				if(v[0][j]>v[1][j])
				k+=v[0][j]-v[1][j];
				else
				k+=v[1][j]-v[0][j];
			}
		cout<<k;
		return 0;
	}
	else
	{
		cout<<-1;
		return 0;
	}
}
int check(int a,int v[3])
{
	while(a%2==0)
	{
		v[0]++;
		a=a/2;
	}
	while(a%3==0)
	{
		v[1]++;
		a=a/3;
	}
	while(a%5==0)
	{
		v[2]++;
		a=a/5;
	}
	return a;
}
