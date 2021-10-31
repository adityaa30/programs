#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
void solve(){
    ll a,b,x,y,n;
    cin>>a>>b>>x>>y>>n;
    ll r = a-(min(n,a-x));
    ll s = b-(min(n,b-y));
    if(r<=s){
        if(n>a-x){
            ll c = b-(n-a+x);
            if(c<y)
                b = y; 
            else
                b = b-(n-a+x);
            a = x;
        }
        else{
            a = a-n;
        }
    }
    else{
        if(n>b-y){
            ll d = a-(n-b+y);
            if(d<x)
                a = x;
            else
                a = a-(n-b+y);
            b = y;
        }
        else{
            b = b-n;
        }
    }
    ll ans = a*b;
    cout<<ans<<endl;
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
