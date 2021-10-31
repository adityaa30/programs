#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

vector<int> parent;
vector<int> level;
void dfs(int s, int p, int l = 0) {
    parent[s] = p;
    level[s] = l;
    for (auto i : v[s]) {
        if (i != p) {
            dfs(i, s, l + 1);
        }
    }
}
vector<vector<int>> dp;
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

void solve() {
    int n, q;
    cin >> n >> q;
    v = vector<vector<int>>(n);
    parent = vector<int>(n);
    level = vector<int>(n);
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        cin >> a >> b;
        v[--b].push_back(--a);
        v[a].push_back(b);
    }
    dfs(0, -1);
    dp = vector<vector<int>>(n, vector<int>(20, -1));
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
    while (q--) {
        int a, b;
        cin >> a >> b, a--, b--;
        int LCA = lca(a, b);
        cout << level[a] + level[b] - 2 * level[LCA] << "\n";
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << setprecision(10);

    int t = 1;
    // cin>>t;

    for (int i = 1; i <= t; i++) {
        // cout<<"Case "<<i<<": ";
        solve();
    }
}