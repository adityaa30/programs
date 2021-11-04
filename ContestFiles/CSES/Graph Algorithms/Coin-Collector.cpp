#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
  int n, m;
  cin >> n >> m;

  vector<int> coins(n);
  for (int i = 0; i < n; ++i) {
    cin >> coins[i];
  }

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
      mark(x, v++);
    }
  }

  // combine all nodes in same component
  vector<set<int>> compressed_adj(v);
  vector<int> compressed_coins(v);
  for (int from = 0; from < n; ++from) {
    compressed_coins[group[from]] += coins[from];

    for (int to : adj[from]) {
      compressed_adj[group[from]].insert(group[to]);
    }

    compressed_adj[group[from]].erase(group[from]);
  }

  vector<int> dp(v, -1); // dp[i] = mx cost if we start at this node
  function<int(int)> go = [&](int x) {
    if (dp[x] != -1) {
      return dp[x];
    }

    dp[x] = compressed_coins[x];
    for (int child : compressed_adj[x]) {
      dp[x] = max(dp[x], compressed_coins[x] + go(child));
    }

    return dp[x];
  };

  for (int i = 0; i < v; ++i) {
    go(i);
  }

  cout << *max_element(dp.begin(), dp.end()) << '\n';

  return 0;
}