#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define mod 1000000007
 
#define p(x) cout<<x<<" ";
#define p2(x,y) cout<<x<<" "<<y<<" "
#define p3(x,y,z) cout<<x<<" "<<y<<" "<<z<<" "
#define F(i,a,b) for(ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
 
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pi pair<ll,ll>
#define ppi pair<ll,pi>
#define pb push_back
#define all(v) v.begin(), v.end() 
 
ll dp[105];
 
ll solve(ll n,ll k,ll j){
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	if(dp[n]!=-1)
		return dp[n];
	ll ans=0;
	for(ll i=1;i<=k;i++){
		ans+=solve(n-i,k,j);
		ans%=mod;
	}
	dp[n]=ans;
	return ans;
}
 
int main()
{
 
    ll t=1;
    //cin>>t;
    
    while(t--)
    {
      ll n,k,d;
      cin>>n>>k>>d;
      ll y=0;
      memset(dp,-1,sizeof(dp));
      ll x=solve(n,k,n);
      memset(dp,-1,sizeof(dp));
      if(d-1>0)
       y=solve(n,d-1,n);
      cout<<(x-y+mod)%mod<<"\n";
    }
        
}