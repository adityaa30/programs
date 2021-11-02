#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int INF = 1e18;

int32_t main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> rev_adj(n), adj(n);
  vector<array<int, 3>> edges(m);
  for (int i = 0; i < m; ++i) {
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    --edges[i][0], --edges[i][1];
    rev_adj[edges[i][1]].push_back(edges[i][0]);
    adj[edges[i][0]].push_back(edges[i][1]);
  }

  vector<int> D(n, -INF);
  D[0] = 0;
  for (int i = 1; i < n; ++i) {
    for (auto [a, b, w] : edges) {
      D[b] = max(D[b], D[a] + w);
    }
  }

  vector<bool> positive_cycle(n, false);
  for (auto [a, b, w] : edges) {
    if ((D[a] + w) > D[b]) {
      positive_cycle[b] = true;
      positive_cycle[a] = true;
    }
  }

  // check if any path from `1` to `n` has a positive cycle node
  function<void(vector<vector<int>> &, int, vector<bool> &)> dfs =
      [&](vector<vector<int>> &graph, int curr, vector<bool> &visited) {
        visited[curr] = true;
        for (int child : graph[curr]) {
          if (!visited[child]) {
            dfs(graph, child, visited);
          }
        }
      };

  vector<bool> from_1(n, false), from_n(n, false);
  dfs(adj, 0, from_1);
  dfs(rev_adj, n - 1, from_n);

  for (int i = 0; i < n; ++i) {
    if (from_1[i] && from_n[i] && positive_cycle[i]) {
      cout << "-1\n";
      return 0;
    }
  }

  cout << D[n - 1] << '\n';
  return 0;
}
