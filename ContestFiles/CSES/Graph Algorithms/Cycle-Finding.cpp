#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int INF = 1e18;

int32_t main() {
  int n, m;
  cin >> n >> m;

  vector<array<int, 3>> edges(m);
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    --edges[i][0], --edges[i][1];
    adj[edges[i][0]].push_back(edges[i][1]);
  }

  vector<int> D(n, -INF), parent(n, -1);
  int cycle_node = -1;
  D[0] = 0;
  for (int i = 0; i < n; ++i) {
    cycle_node = -1;
    for (auto [a, b, w] : edges) {
      if (D[b] > (D[a] + w)) {
        D[b] = D[a] + w;
        parent[b] = a;
        cycle_node = b;
      }
    }
  }

  if (cycle_node == -1) {
    cout << "NO\n";
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    cycle_node = parent[cycle_node];
  }

  vector<int> cycle(1, cycle_node);
  int curr = parent[cycle_node];

  while (curr != cycle_node) {
    cycle.push_back(curr);
    curr = parent[curr];
  }
  cycle.push_back(curr);
  reverse(cycle.begin(), cycle.end());

  cout << "YES\n";
  for (int x : cycle) {
    cout << (x + 1) << " ";
  }

  return 0;
}
