#include<bits\stdc++.h>
using namespace std;
int main()
{
	int n;
	long long draw=1;
	cin>>n;
	vector<long> v(2*n);
	for(int i=0;i<2*n;i++)
	cin>>v[i];
	draw+=min(v[0],v[1]);
	n;
	if(n>1)
	{
		for(int i=1;i<n;i++)
		{
			draw+=max(min(v[2*i],v[2*i+1])-max(v[2*i-2],v[2*i-1]),(long)0);
		}
		
	}
	cout<<draw;
}
