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

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(char c) { return to_string(string(1, c)); }

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
           to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
           to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void dbg() { cout << endl; }
template <typename Head, typename... Tail>
void dbg(Head H, Tail... T) {
    cout << " " << to_string(H);
    dbg(T...);
}

#ifdef LOCAL
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", dbg(__VA_ARGS__)
#else
#define debug(...)
#endif

vector<vi> v;

vi parent;
vi level;
void dfs(int s, int p, int l = 0) {
    parent[s] = p;
    level[s] = l;
    for (auto i : v[s]) {
        if (i != p) {
            dfs(i, s, l + 1);
        }
    }
}
vector<vi> dp;
int lca(int a, int b) {
    if (level[a] < level[b]) {
        swap(a, b);
    }
    int d = level[a] - level[b];
    for (int i = 19; i >= 0; i--) {
        if (d & (1 << i)) {
            a = dp[a][i];
        }
    }
    if (a == b) {
        return a;
    }
    for (int i = 19; i >= 0; i--) {
        if (dp[a][i] != dp[b][i]) {
            a = dp[a][i], b = dp[b][i];
        }
    }
    return dp[a][0];
}

vi prefix;
void dfs1(int s, int p) {
    for (auto i : v[s]) {
        if (i != p) {
            dfs1(i, s);
            prefix[s] += prefix[i];
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    v = vector<vi>(n);
    parent = vi(n);
    level = vi(n);
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        cin >> a >> b;
        v[--b].pb(--a);
        v[a].pb(b);
    }
    dfs(0, -1);
    dp = vector<vi>(n, vi(20, -1));
    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < n; i++) {
            if (j == 0) {
                dp[i][j] = parent[i];
            } else {
                if (dp[i][j - 1] != -1)
                    dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
    }
    // debug(level);
    prefix = vi(n, 0);
    while (q--) {
        int a, b;
        cin >> a >> b, a--, b--;
        int LCA = lca(a, b);
        prefix[a] += 1;
        prefix[b] += 1;
        prefix[LCA] -= 1;
        if (parent[LCA] != -1) {
            prefix[parent[LCA]] -= 1;
        }
    }
    dfs1(0, -1);
    for (int i = 0; i < n; i++) {
        cout << prefix[i] << " \n"[i == n - 1];
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