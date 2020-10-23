#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int m,n;
	long count=0;
	cin>>n>>m;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	cin>>v[i];
	sort(v.begin(),v.end());
	for(int i=0;i<m;i++)
	{
		if(v[i]<0)
		{
			count-=v[i];
		}
		else
		{
			break;
		}
	}
	cout<<count;
}
