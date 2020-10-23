#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t,j=0,i=0,count=0;
	long s1,s2,e1,e2;
	cin>>t>>s1>>s2>>e1>>e2;
	string s;
	cin>>s;
	if(s1==e1&&s2==e2)
		{
			cout<<0;
			return 0;
		}
	if(e1-s1>=0&&e2-s2>=0)
		for(i=0;i<t;i++)
		{
			if(s1==e1&&s2==e2)
		{	
			break;
		}
		else if(s[i]=='N'&&s2!=e2)
			{count++;
			s2++;
			}
		else if(s[i]=='E'&&s1!=e1)
			{count++;
			s1++;
			}
		}
	else if(e1-s1<0&&e2-s2>=0)
		for(i=0;i<t;i++)
		{
			if(s1==e1&&s2==e2)
		{
			break;
		}
		else if(s[i]=='N'&&s2!=e2)
			{count++;
			s2++;
			}
		else if(s[i]=='W'&&s1!=e1)
			{count++;
			s1--;
			}
		}
		else if(e1-s1<0&&e2-s2<0)
		for(i=0;i<t;i++)
		{
			if(s1==e1&&s2==e2)
		{
			break;
		}
		else if(s[i]=='S'&&s2!=e2)
			{count++;
			s2--;
			}
		else if(s[i]=='W'&&s1!=e1)
			{count++;
			s1--;
			}
		}
		else if(e1-s1>=0&&e2-s2<0)
		for(i=0;i<t;i++)
		{
			if(s1==e1&&s2==e2)
		{
			break;
		}
		else if(s[i]=='S'&&s2!=e2)
			{count++;
			s2--;
			}
		else if(s[i]=='E'&&s1!=e1)
			{count++;
			s1++;
			}
		}
	if(s1==e1&&s2==e2)
		{
			cout<<i;
			return 0;
		}
	else
		cout<<-1;
	
		
}
