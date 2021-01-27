// https://cses.fi/problemset/task/1687
#include "../../../BinaryLifting/Template.hpp"
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int n, Q;
  cin >> n >> Q;
  vector<vector<int>> adj(n + 1);
  for (int i = 2; i <= n; ++i) {
    int u = i, v;
    cin >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  BinaryLift lift(adj, 1);
  for (int q = 0; q < Q; ++q) {
    int x, k;
    cin >> x >> k;
    cout << lift.Parent(x, k) << '\n';
  }

  return 0;
}