#include<bits\stdc++.h>
using namespace std;
int main()
{
	int n,m;
	int sum=0;
	cin>>n>>m;
	sum=m;
	vector<int> v(n);
	for(int i=0;i<n;i++)cin>>v[i],sum+=v[i];
	sort(v.begin(),v.end());
	if(sum%n==0)
		cout<<max(sum/n,v[n-1])<<" "<<v[n-1]+m;
	else
		cout<<max(sum/n+1,v[n-1])<<" "<<v[n-1]+m;
	
}

