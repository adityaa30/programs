#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    int j = n-1;
    int d;
    while(true){
        if((y-x)%j == 0){
            d = (y-x)/j;   
            break;         
        }
        else{
            j--;
        };
    }
    int a=y;
    int k = n-1;
    while(k>0){
        if(a-d>0){
            k--;
            a = a-d;
        }
        else{
            break;
        }
    }
    for(int i=0; i<n; i++){
        cout<<a<<" ";
        a=a+d;
    }
    cout<<endl;
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
