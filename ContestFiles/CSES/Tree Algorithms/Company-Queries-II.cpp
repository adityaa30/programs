// https://cses.fi/problemset/task/1688
#include "Template-LCA.hpp"
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int n, Q;
  cin >> n >> Q;
  vector<vector<int>> adj(n + 1);
  for (int u = 2; u <= n; ++u) {
    int v;
    cin >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  BinaryLiftLCA lift(adj, 1);
  for (int q = 0; q < Q; ++q) {
    int u, v;
    cin >> u >> v;
    cout << lift.LCA(u, v) << '\n';
  }

  return 0;
}