#include<bits\stdc++.h>
using namespace std;
long gcd(long,long);
int main()
{int t;
cin>>t;
while(t--)
{
	int n;
	cin>>n;
	char s[n][n];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		cin>>s[i][j];
	}
	if(s[0][1]=='0'&&s[1][0]=='0')
	{
		if(s[n-1][n-2]=='1'&&s[n-2][n-1]=='1')
		{
			cout<<0<<"\n";
		}
		else if(s[n-1][n-2]=='1'&&s[n-2][n-1]=='0')
		{cout<<1<<"\n";
		cout<<n-1<<" "<<n<<"\n";
		}
		else if(s[n-1][n-2]=='0'&&s[n-2][n-1]=='1')
		{cout<<1<<"\n";
		cout<<n<<" "<<n-1<<"\n";
		}
		else
		{cout<<2<<"\n";
		cout<<n-1<<" "<<n<<"\n";
		cout<<n<<" "<<n-1<<"\n";}
		
	}
	else if(s[0][1]=='1'&&s[1][0]=='0')
	{
		if(s[n-1][n-2]=='1'&&s[n-2][n-1]=='1')
		{
			cout<<1<<"\n";
			cout<<1<<" "<<2<<"\n";
		}
		else if(s[n-1][n-2]=='1'&&s[n-2][n-1]=='0')
		{cout<<2<<"\n";
		cout<<1<<" "<<2<<"\n";
		cout<<n-1<<" "<<n<<"\n";
		}
		else if(s[n-1][n-2]=='0'&&s[n-2][n-1]=='1')
		{cout<<2<<"\n";
		cout<<1<<" "<<2<<"\n";
		cout<<n<<" "<<n-1<<"\n";
		}
		else
		{cout<<1<<"\n";
			cout<<2<<" "<<1<<"\n";}
	}
	else if(s[0][1]=='0'&&s[1][0]=='1')
	{
		if(s[n-1][n-2]=='1'&&s[n-2][n-1]=='1')
		{
			cout<<1<<"\n";
			cout<<2<<" "<<1<<"\n";
		}
		else if(s[n-1][n-2]=='1'&&s[n-2][n-1]=='0')
		{cout<<2<<"\n";
		cout<<2<<" "<<1<<"\n";
		cout<<n-1<<" "<<n<<"\n";
		}
		else if(s[n-1][n-2]=='0'&&s[n-2][n-1]=='1')
		{cout<<2<<"\n";
		cout<<2<<" "<<1<<"\n";
		cout<<n<<" "<<n-1<<"\n";
		}
		else
		{cout<<1<<"\n";
			cout<<1<<" "<<2<<"\n";}
	}
	else
	{
		if(s[n-1][n-2]=='0'&&s[n-2][n-1]=='0')
		{
			cout<<0<<"\n";
		}
		else if(s[n-1][n-2]=='0'&&s[n-2][n-1]=='1')
		{cout<<1<<"\n";
		cout<<n-1<<" "<<n<<"\n";
		}
		else if(s[n-1][n-2]=='1'&&s[n-2][n-1]=='0')
		{cout<<1<<"\n";
		cout<<n<<" "<<n-1<<"\n";
		}
		else
		{cout<<2<<"\n";
		cout<<n-1<<" "<<n<<"\n";
		cout<<n<<" "<<n-1<<"\n";}
	}
	
}
	
}
