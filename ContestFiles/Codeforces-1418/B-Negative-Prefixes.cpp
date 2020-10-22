#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define f(i, a, n) for (int i = a; i < n; i++)
#define f1(i, a, n) for (int i = n; i >= a; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vbl vector<bool>
#define upb upper_bound
#define lwb lower_bound
#define umap unordered_map
#define uset unordered_set
#define gcd __gcd
const ll MOD = 1e9 + 7;
#define INF 1e15
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        ll arr[n], unl[n];
        ll sum = 0;
        for(int i = 0; i < n; i++) {cin >> arr[i]; sum += arr[i];}
        for(int i = 0; i < n; i++) cin >> unl[i];
        if(sum < 0)
        {
            for(int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << "\n";
            continue;
        }
        vll neg, pos;
        for(int i = 0; i < n; i++)
        {
            if(unl[i] == 0)
            {
                if(arr[i] < 0)
                neg.pb(arr[i]);
                else pos.pb(arr[i]);
            }
        }
        sort(neg.begin(), neg.end());
        sort(pos.begin(), pos.end());
        int psz = pos.size(), nsz = neg.size();
        int ip = 0, ing = 0;
        vll ans;
        for(int i = n-1; i>=0; i--)
        {
            if(unl[i] == 1) ans.pb(arr[i]);
            else 
            {
                if(ing < nsz)
                {
                    ans.pb(neg[ing]);
                    ing ++;
                }
                else
                {
                    ans.pb(pos[ip]);
                    ip ++;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        for(auto a : ans) cout << a << " "; cout << "\n";
    }
    return 0;
}