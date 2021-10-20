#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define vi vector<ll>
const long long mod = 1000000007LL;

#define ff first
#define ss second
#define pi pair<ll, ll>
#define pb push_back
#define all(v) v.begin(), v.end()
const ll inf = 1e18;

inline int max(int a, int32_t b) { return a > b ? a : b; }
inline int max(int32_t a, int b) { return a > b ? a : b; }
inline int min(int a, int32_t b) { return a < b ? a : b; }
inline int min(int32_t a, int b) { return a < b ? a : b; }
int d4_1[4] = {1, 0, -1, 0};
int d4_2[4] = {0, 1, 0, -1};
int d8_1[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int d8_2[8] = {0, -1, 1, 0, -1, 1, 1, -1};

vector<vi> v;

vi start_time;
vi end_time;
vi order;
int t = 1;
void dfs(int s, int p) {
    order.pb(s);
    start_time[s] = t++;
    for (auto i : v[s]) {
        if (i != p) {
            dfs(i, s);
        }
    }
    end_time[s] = t - 1;
}

vi cost;
vi bit;

void update(int x, int val, int n) {
    for (; x <= n; x += x & (-x)) {
        bit[x] += val;
    }
}
int query(int x) {
    int ans = 0;
    for (; x > 0; x -= x & (-x)) {
        ans += bit[x];
    }
    return ans;
}

void solve() {
    int n, q;
    cin >> n >> q;
    v = vector<vi>(n + 1);
    cost = start_time = end_time = vi(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        cin >> a >> b;
        v[b].pb(a);
        v[a].pb(b);
    }
    dfs(1, -1);

    bit = vi(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        update(start_time[i], cost[i], n);
        update(end_time[i] + 1, -cost[i], n);
    }
    while (q--) {
        int ch;
        cin >> ch;
        if (ch == 1) {
            int x, y;
            cin >> x >> y;
            update(start_time[x], y - cost[x], n);
            update(end_time[x] + 1, -y + cost[x], n);
            cost[x] = y;
        } else {
            int x;
            cin >> x;
            cout << query(start_time[x]) << "\n";
        }
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << setprecision(10);

    ll t = 1;
    // cin>>t;

    for (int i = 1; i <= t; i++) {
        // cout<<"Case "<<i<<": ";
        solve();
    }
}