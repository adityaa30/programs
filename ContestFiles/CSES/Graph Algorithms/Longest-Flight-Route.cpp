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

  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(i);
    }
  }

  reverse(topo.begin(), topo.end());
  vector<int> D(n, -INF), parent(n, -1);
  D[0] = 1;
  for (int curr : topo) {
    for (int child : adj[curr]) {
      if (D[child] < (1 + D[curr])) {
        D[child] = 1 + D[curr];
        parent[child] = curr;
      }
    }
  }

  if (D[n - 1] <= 0) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  vector<int> path;
  for (int x = n - 1; x != -1; x = parent[x]) {
    path.push_back(x);
  }

  reverse(path.begin(), path.end());
  assert(path.size() == D[n - 1]);
  cout << D[n - 1] << '\n';
  for (int x : path) {
    cout << (x + 1) << ' ';
  }
  cout << '\n';

  return 0;
}
