#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int INF = 1e18;

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

  bool has_cycle = false;
  vector<bool> visited(n, false), in_path(n, false);
  vector<int> topo;

  function<void(int)> dfs = [&](int curr) {
    if (has_cycle)
      return;

    visited[curr] = in_path[curr] = true;

    for (int child : adj[curr]) {
      if (!visited[child]) {
        dfs(child);
      } else if (in_path[child]) {
        has_cycle = true;
        return;
      }
    }

    in_path[curr] = false;
    topo.push_back(curr);
  };

  for (int i = 0; i < n; ++i) {
    if (!visited[i] && !has_cycle) {
      dfs(i);
    }
  }

  if (has_cycle) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  reverse(topo.begin(), topo.end());
  for (int x : topo) {
    cout << (x + 1) << ' ';
  }
  cout << '\n';

  return 0;
}
