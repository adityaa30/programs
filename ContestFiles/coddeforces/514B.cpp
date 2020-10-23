#include<bits\stdc++.h>
using namespace std;
int main()
{
	int n,a,b,o,p,k=1;
	cin>>n>>a>>b;
	vector< pair<int,int> > x(n);
	for(int i=0;i<n;i++)
	{cin>>o>>p;
	x.push_back(make_pair(o-a,p-b));}
	vector<long double> c(n);
	for(int i=0;i<n;i++)
	{	if(x[i].first!=0)
		c[i]=(long double)x[i].second/x[i].first;
		else 
		c[i]=100000;
	}
	sort(c.begin(),c.end());
	for(int i=0;i<n-1;i++)
	{
		if(c[i]!=c[i+1])
		k++;
	}
	cout<<k;
	
}
