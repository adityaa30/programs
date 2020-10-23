#include<bits\stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long sum=0,n,k;
		cin>>n>>k;
		vector<int> v(n+2);
		string s;
		cin>>s;
		if(s[0]=='W')
		v[1]=1,v[0]=0;
		else
		v[1]=0,v[0]=0;
		v[n+1]=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='L')
			v[i+1]=0;
			else if(s[i]=='W'&&s[i-1]=='W')
			v[i+1]=2;
			else
			v[i+1]=1;
		}
		for(int i=0;i<n+2;i++)
		{
			
			sum+=v[i];
		}
		while(k--)
		{
			for(int i=1;i<n+1;i++)
		{
			if((v[i]==0&&v[i+1]==1)&&(v[i-1]==1||v[i-1]==2))
			{
				sum+=3;
				v[i]=2;
				v[i+1]=2;
			}
			
			else if(v[i]==0&&v[i+1]==1)
			{
				sum+=2;
				v[i]=1;
				v[i+1]=2;
			}
			else if(v[i]==0&&(v[i-1]==1||v[i-1]==2))
			{
				sum+=2;
				v[i]=2;
			}
			else if(v[i]==0)
			{
				sum++;
				v[i]=1;
			}
		}
		}
		cout<<sum<<"\n";
	}
}
