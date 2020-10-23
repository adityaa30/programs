#include<bits\stdc++.h>
using namespace std;
int main()
{
	long a,b,n;
	cin>>a>>b>>n;
	string s;
	int i=0;
	for(i=0;i<10;i++)
	{
		if((a*10+i)%b==0)
		{	a=a*10+i;
			i=-1;
			n--;
			break;
		}
	}
	if(i!=-1)
	{
		cout<<-1;
	}
	else{
		cout<<a;
		while(n--)
			cout<<0;
	}
	
}
