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
  vector<int> topo;

  function<void(int)> topo_sort = [&](int curr) {
    visited[curr] = true;
    for (int child : adj[curr]) {
      if (!visited[child]) {
        topo_sort(child);
      }
    }

    topo.push_back(curr);
  };

  vector<int> group(n, -1);
  function<void(int, int)> mark = [&](int curr, int what) {
    group[curr] = what;
    for (int child : rev_adj[curr]) {
      if (group[child] == -1) {
        mark(child, what);
      }
    }
  };

  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      topo_sort(i);
    }
  }
  reverse(topo.begin(), topo.end());

  int v = 0;
  for (int x : topo) {
    if (group[x] == -1) {
      mark(x, ++v);
    }
  }


  cout << v << '\n';
  for (int x : group) {
    cout << x << ' ';
  }

  return 0;
}