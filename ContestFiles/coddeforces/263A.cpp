#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int i=0,j=0,x=0,y=0;
	vector<string> s(5);
	for(i=0;i<5;i++)
	for(j=0;j<5;j++)
	{
		cin>>s[i][j];
		if(s[i][j]=='1')
		x=i,y=j;
	}
	x=max(x-2,2-x),y=max(y-2,2-y);
	cout<<x+y;
}
