#include<bits\stdc++.h>
using namespace std;
int main()
{
	int n,s,t,count=0;
	cin>>n>>s>>t;
	vector<int> v(n+1);
	for(int i=1;i<=n;i++)
	cin>>v[i];
	while(t!=s)
	{
		if((s==v[s]&&s!=t)||count>n)
		{
			cout<<-1;
			return 0;
		}
		else if(t!=s)
		{
			count++;
			s=v[s];	
		}
		
	}
	cout<<count;
}
