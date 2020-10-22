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

ll n;
vll arr;
vector<vll> dp;

ll solve(ll pos, ll type)
{
    if(pos >= n) return 0;
    if(dp[pos][type] != -1) return dp[pos][type];
    if(type == 1)
    {
        dp[pos][type] = min(solve(pos+1, 1-type), solve(pos+2, 1-type));
    }
    else 
    {
        dp[pos][type] = arr[pos] + solve(pos+1, 1-type);
        if(pos < (n-1)) dp[pos][type] = min(dp[pos][type], arr[pos] + arr[pos+1] + solve(pos+2, 1 - type));
    }
    return dp[pos][type];
}

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
        cin >> n;
        arr.resize(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        dp.clear();
        dp.resize(n, vll(2, -1));
        ll ans = solve(0, 0);
        cout << ans << "\n";
    }
    return 0;
}