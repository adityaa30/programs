#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mp make_pair
#define pb push_back
#define pii pair<int,int> 
#define pli pair<long long int,int> 
 
void solve(){
    ll n;  cin>>n;
    ll  a[n];
    for(ll i=0; i<n; i++)
        cin>>a[i];
    
    ll i=0;
    ll sum=0, maxi = INT_MIN;
    bool flag=true;
    if(a[0]>0){
        flag=true;
        maxi = a[0];
    }
    else{
        flag=false;
        maxi=a[0];
    }
    for(ll i=1; i<n; i++){
        if(flag && a[i]>0){
            maxi = max(a[i], maxi);
        }
        else if(flag && a[i]<0){
            flag = false;
            sum += maxi;
            maxi = INT_MIN;
            maxi = max(a[i], maxi);
        }
        else if(!flag && a[i]<0){
            maxi = max(a[i], maxi);
        }
        else if(!flag && a[i]>0){
            flag =true;
            sum+=maxi;
            maxi = INT_MIN;
            maxi = max(a[i], maxi);
        }
    }
    sum += maxi;
    cout<<sum<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
