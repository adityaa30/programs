#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n][3],b[3]={0,0,0};
	for(int i=0; i<n;i++)
		{for(int j=0;j<3;j++)
		{cin>>a[i][j];
		}
		}
	for(int j=0;j<3;j++)
	{for(int i=0; i<n;i++)
	{b[j]=a[i][j]+b[j];
	}}
	if(b[0]==0&&b[1]==0&&b[2]==0)
		cout<<"YES";
	else
		cout<<"NO";
}
