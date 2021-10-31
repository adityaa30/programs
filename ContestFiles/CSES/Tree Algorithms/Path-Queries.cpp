#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

vector<int> start_time;
vector<int> end_time;
vector<int> order;
int t = 1;
void dfs(int s, int p) {
    order.push_back(s);
    start_time[s] = t++;
    for (auto i : v[s]) {
        if (i != p) {
            dfs(i, s);
        }
    }
    end_time[s] = t - 1;
}

vector<int> cost;
vector<int> bit;

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
    v = vector<vector<int>>(n + 1);
    cost = start_time = end_time = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
        v[a].push_back(b);
    }
    dfs(1, -1);
    bit = vector<int>(n + 1, 0);
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

    int t = 1;
    // cin>>t;

    for (int i = 1; i <= t; i++) {
        // cout<<"Case "<<i<<": ";
        solve();
    }
}