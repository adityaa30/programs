#include "AdjacencyList.hpp"
#include <bits/stdc++.h>
using namespace std;

const int NO_PARENT = -1;

vector<pair<int, int>> GetBridges(vector<vector<int>> &adj) {
  int N = (int)adj.size(); // 0-Indexed
  vector<pair<int, int>> bridges;

  vector<bool> visited(N, false);
  vector<int> entryTime(N), low(N);
  int timer = 0;

  function<void(int, int)> dfs = [&](int curr, int parent) {
    visited[curr] = true;
    entryTime[curr] = low[curr] = timer++;

    for (int child : adj[curr]) {
      if (child == parent) continue;
      else if (visited[child]) {
        low[curr] = min(low[curr], entryTime[child]);
      } else {
        dfs(child, curr);
        low[curr] = min(low[curr], low[child]);
        if (low[child] > entryTime[curr]) {
          // no backedge from any successor of `child` to any ancestor of `curr`
          // hence `curr <-> child` is a bridge 
          bridges.push_back({curr, child});
        }
      }
    }
  };

  for (int i = 0; i < N; ++i) {
    if (!visited[i]) {
      dfs(i, NO_PARENT);
    }
  }
  return bridges;
}

vector<pair<int, int>> GetBridgesDpBased(vector<vector<int>> &adj) {
  int N = (int) adj.size();
  vector<pair<int, int>> bridges;
  vector<int> level(N, 0); // 0 -> Means vertex not yet reached
  vector<int> dp(N, 0); // Number of back-edges/paths around i<->parent[i]
  
  function<void(int, int)> dfs = [&](int curr, int parent) {
    dp[curr] = 0;
    for (int child : adj[curr]) {
      if (child == parent) continue;
      else if (level[child] == 0) {
        level[child] = level[curr] + 1;
        dfs(child, curr);
        dp[curr] += dp[child];
      } else if (level[child] < level[curr]) {
        dp[curr]++;
      } else if (level[child] > level[curr]) {
        dp[curr]--; // This back-edge is already counted from the curr <-> child dp.
      }
    }

    // Finally if there is no backedges around curr <-> parent then it is a bridge
    if (dp[curr] == 0 && parent != NO_PARENT) {
      bridges.push_back({curr, parent});
    }
  };

  level[0] = 1;
  dfs(0, NO_PARENT);

  return bridges;
}

int32_t main() {
  vector<vector<int>> adj1 = {{1, 2, 3}, {0}, {0, 3}, {0, 2, 4}, {3}};
  auto bridges1 = GetBridges(adj1);
  for (pair<int, int> bridge : bridges1) {
    cout << bridge.first << ' ' << bridge.second << '\n';
  }

  auto adj2 = GetAdjacencyList({
    {0, 1},
    {1, 2},
    {2, 3},
    {3, 0},
  }, true);
  auto bridges2 = GetBridges(adj2);
  for (pair<int, int> bridge : bridges2) {
    cout << bridge.first << ' ' << bridge.second << '\n';
  }

  return 0;
}