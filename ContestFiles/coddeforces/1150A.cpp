#include<bits\stdc++.h>
using namespace std;
int main()
{
	int n,m,r;
	cin>>n>>m>>r;
	int b[n],s[m];
	for(int i=0;i<n;i++)
		cin>>b[i];
	for(int i=0;i<m;i++)
		cin>>s[i];
	sort(b,b+n);
	sort(s,s+m);
	if(b[0]>=s[m-1])
	{cout<<r;
	}
	else
	{
		int temp=r%b[0];
		n=r/b[0];
		r=temp+s[m-1]*n;
		cout<<r<<"\n";
		
	}
}
