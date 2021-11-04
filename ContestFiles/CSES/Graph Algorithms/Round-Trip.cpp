#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> path;
  vector<bool> visited(n, false), in_path(n, false);

  function<bool(int, int)> dfs = [&](int parent, int curr) {
    visited[curr] = in_path[curr] = true;
    path.push_back(curr);

    for (int child : adj[curr]) {
      if (child == parent) {
        continue;
      }
      if (!visited[child]) {
        bool cycle_found = dfs(curr, child);
        if (cycle_found) {
          return true;
        }
      } else if (in_path[child]) {
        path.push_back(child);
        return true;
      }
    }

    path.pop_back();
    in_path[curr] = false;
    return false;
  };

  for (int i = 0; i < n; ++i) {
    if (!visited[i] && dfs(-1, i)) {
      int start = -1;
      for (int i = 0; i < path.size(); ++i) {
        if (path[i] == path.back()) {
          start = i;
          break;
        }
      }
      cout << (path.size() - start) << '\n';
      for (int i = start; i < path.size(); ++i) {
        cout << (path[i] + 1) << ' ';
      }
      cout << '\n';
      return 0;
    }
  }

  cout << "IMPOSSIBLE\n";

  return 0;
}