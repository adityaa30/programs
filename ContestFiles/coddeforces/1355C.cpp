#include<bits/stdc++.h>
using namespace std;
int main()
{
	unsigned int a,b,c,d,x,y,z,count=0;
	cin>>a>>b>>c>>d;
	for(x=b;x>=a;x--) 
	{
		for(y=c;y>=b;y--)
		{
			for(z=c;z<=d;z++)
			{
				if(x+y>z)
				{
					count++;
				}
			}
		}
	 }
	 cout<<count;
	 return 0; 
}
