#include<iostream>
using namespace std;
int main()
{
   unsigned long long  int x,y,n;
    cin>>x>>y>>n;
    unsigned long long int mod=1000000007;
    unsigned long long c;
 
    n=n%6;
 
    if(n==1)
    {
        c=x+10*mod;
        cout<<c%mod;
    }
    if(n==2)
    {
        c=y+10*mod;
        cout<<(c)%mod;
    }
    if(n==3)
    {
        c=y-x+10*mod;
        cout<<(c)%mod;
    }
    if(n==4)
    {
        c=-x+10*mod;
        cout<<(c)%mod;
    }
    if(n==5)
    {
        c=-y+10*mod;
        cout<<(c)%mod;
    }
    if(n==0)
    {
        c=x-y+10*mod;
        cout<<(c)%mod;
    }
}
