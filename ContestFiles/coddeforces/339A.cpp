#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int l=s.size();
	for(int j=0;j<l/2;j++)
	for(int i=0;i<l/2;i++)
	{	char a;
		if(s[2*i]>s[2*i+2])
		{
			a=s[2*i];
			s[2*i]=s[2*i+2];
			s[2*i+2]=a;
			
		}
	}
	cout<<s<<"\n";
}
