#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string s,a;
	cin>>a;
	int l=a.size();
	for(int i=0;i<l;i++)
	{
		if(a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U'||a[i]=='Y'||a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='y')
		{
		}
		else
		{s.push_back('.');
		if(a[i]>='a'&&a[i]<='z')
			s.push_back(a[i]);
		else
			s.push_back(a[i]+32);
		}
	}
	cout<<s;
}
