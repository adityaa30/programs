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
        ll x, y, k; cin >> x >> y >> k;
        ll ans = (y+1)*k - 1;
        ll res = k;
        res += (ans / (x-1));
        if(ans%(x-1) > 0) res ++;
        cout << res << "\n";
    }
    return 0;
}