#include<bits\stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	while(true)
	{	if(v[0]==0)
		{	cout<<"R";
			break;}
		cout<<"P";
		v[0]--;
		if(v[0]>0)
			cout<<"R"<<"L";
				
	}
	for(int i=1;i<n-1;i++)
	{
		while(true)
		{	if(v[i]==0)
		{cout<<"R";
		break;
		}
			cout<<"P";
		v[i]--;
		if(v[i]>0)
			cout<<"L"<<"R";
		
		}
	}
		while(true)
		{	if(v[n-1]==0)
		{cout<<"\n";
		break;
		}
			cout<<"P";
		v[n-1]--;
		if(v[n-1]>0)
			cout<<"L"<<"R";
		
		}
}
