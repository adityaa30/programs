#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,count=0;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++)
		cin>>a[i]>>b[i];
	for(int i=0;i<n;i++)
	{for(int j=0;j<n;j++)
	{
		if(a[i]==b[j]&&i!=j)
		{	count++;
			break;
		}
		
	}
	}
	cout<<n-count;
	
}
