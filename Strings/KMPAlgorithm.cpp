#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
vector<int> generateLPS(string pat){
    int n = pat.length();
    vector<int> lps(n);
    lps[0] = 0;
    int j;
    for(int i=1; i<n; i++){
        j = lps[i-1];
        while(j>0 && pat[i]!=pat[j]){
            j = lps[j-1];
        }
        if(pat[i]==pat[j])
            j++;
        lps[i] = j;
    }
    return lps;
} 

int main(){
    // cin>>t;
    string pat, t;
	cin>>pat>>t;
    int ans = 0;
    vector<int> lps = generateLPS(pat);
    int i=0, j=0;
    while(i<t.length()){
        if(pat[j]==t[i]){
            i++; j++;
        }
        if(j==pat.length()){
            ans++;
            j=lps[j-1];
        }   
        else if(i<t.length() && pat[j]!=t[i]){
            if(j!=0)
                j = lps[j-1];
            else
                i++;    
        }
    }
    cout<<ans<<endl;
}