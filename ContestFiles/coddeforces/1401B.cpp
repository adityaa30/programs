#include<iostream>
using namespace std;
int main()
{ int t;
	cin>>t;
	while(t--)
	{
		long a,b,c,d,e,f,sum=0;
		cin>>a>>b>>c>>d>>e>>f;
		long n=a+b+c;
		long temp;
		sum+=min(c,e)*2;
		temp=min(c,e);
		c=c-temp;
		e=e-temp;
		if(c==0)
		{	temp=min(b,e);
			b=b-temp;
			e=e-temp;
			b=b-min(b,d);
			temp=min(f,a);
			f=f-temp;
			a=a-temp;
			f=f-min(f,a);
			sum-=2*min(b,f);
			f=f-min(f,b);
			
			
		}
		else{
			temp=min(f,c);
			c=c-temp;
			f=f-temp;
			temp=min(f,a);
			f=f-temp;
			a=a-temp;
			b=b-min(b,d);
			sum-=2*min(b,f);
			b=b-min(b,f);
			f=f-min(f,b);
			
		}
		cout<<sum<<"\n";
		
	}
	
}
