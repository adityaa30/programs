#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n), rev_adj(n);

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;

    adj[a].push_back(b);
    rev_adj[b].push_back(a);
  }

  vector<bool> visited(n, false);

  function<void(vector<vector<int>> &, int)> dfs =
      [&](vector<vector<int>> &graph, int curr) {
        visited[curr] = true;
        for (int child : graph[curr]) {
          if (!visited[child]) {
            dfs(graph, child);
          }
        }
      };

  dfs(adj, 0);
  for (int i = 1; i < n; ++i) {
    if (!visited[i]) {
      cout << "NO\n" << 1 << ' ' << (i + 1) << '\n';
      return 0;
    }
  }

  fill(visited.begin(), visited.end(), false);
  dfs(rev_adj, 0);
  for (int i = 1; i < n; ++i) {
    if (!visited[i]) {
      cout << "NO\n" << (i + 1) << ' ' << 1 << '\n';
      return 0;
    }
  }

  cout << "YES\n";

  return 0;
}