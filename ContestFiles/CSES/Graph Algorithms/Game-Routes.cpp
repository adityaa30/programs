#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int INF = 1e18;
const int MOD = 1e9 + 7;

int32_t main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
  }

  vector<bool> visited(n, false);
  vector<int> topo;

  function<void(int)> dfs = [&](int curr) {
    visited[curr] = true;

    for (int child : adj[curr]) {
      if (!visited[child]) {
        dfs(child);
      }
    }

    topo.push_back(curr);
  };

  dfs(0);
  reverse(topo.begin(), topo.end());

  vector<int> cnt(n, 0);
  cnt[0] = 1;
  for (int curr : topo) {
    for (int child : adj[curr]) {
      cnt[child] += cnt[curr];
      cnt[child] %= MOD;
    }
  }

  cout << cnt[n - 1] << '\n';

  return 0;
}
