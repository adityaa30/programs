#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> GetBridges(vector<vector<int>> &adj) {
  int N = adj.size(); // 0-Indexed
  vector<pair<int, int>> bridges;

  vector<bool> visited(N, false);
  vector<int> discoverTime(N), low(N), parent(N);
  int time = 0;

  function<void(int)> dfs = [&](int curr) {
    visited[curr] = true;
    discoverTime[curr] = low[curr] = ++time;
    
    for (int child : adj[curr]) {
      if (!visited[child]) {
        parent[child] = curr;
        dfs(child);
        low[curr] = min(low[curr], low[child]);
        if (low[child] > discoverTime[curr]) {
          bridges.push_back({curr, child});
        }
      } else if (child != parent[curr]) {
        low[curr] = min(low[curr], discoverTime[child]);
      }
    }
  };

  for (int i = 0; i < N; ++i) {
    if (!visited[i]) {
      dfs(i);
    }
  }
  return bridges;
}

int32_t main() {
  vector<vector<int>> adj = {{1, 2, 3}, {0}, {0, 3}, {0, 2, 4}, {3}};
  auto bridges = GetBridges(adj);
  for (pair<int, int> bridge : bridges) {
    cout << bridge.first << ' ' << bridge.second << '\n';
  }

  return 0;
}