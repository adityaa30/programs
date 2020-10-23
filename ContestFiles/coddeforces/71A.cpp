#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	string s;
	char a[4];
	cin>>s;
	int l=s.size();
	 if(l<=10){
		cout<<s<<"\n";
	}
	else if(l>11)
	{l=l-2;
	a[0]=s[0];
	a[1]=l/10+48;
	a[2]=l%10+48;
	a[3]=s[l+1];
	cout<<a[0]<<a[1]<<a[2]<<a[3]<<"\n";
	}
	else if(l=11)
	{l=l-2;
	a[0]=s[0];
	a[1]=l+48;
	a[2]=s[l+1];
	cout<<a[0]<<a[1]<<a[2]<<"\n";
	}
	}

}
