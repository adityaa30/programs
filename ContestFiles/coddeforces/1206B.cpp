#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	long a,b=0,c=0;
	long long count=0;
	cin>>n;
	vector<long> v;
	for(int i=0;i<n;i++){
	cin>>a;
	v.push_back(a);}
	a=0;
	for(int i=0;i<n;i++)
	{
		if(v[i]>0)
		{
			count+=v[i]-1;
			a++;
		}
		else if(v[i]<0)
		{
			count+=-1-v[i];
			b++;
		}
		if(v[i]==0)
		{
			count++;
			c++;
		}
	}
	if(b%2==0||c>0)
	{
		cout<<count;
	}
	else
		cout<<count+2;
}
