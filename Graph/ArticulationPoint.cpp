#include "../Misc/AdjacencyList.hpp"
#include <bits/stdc++.h>
using namespace std;

const int NO_PARENT = -1;

set<int> GetArticulationPoints(vector<vector<int>> &adj) {
  int N = (int)adj.size(); // 0-Indexed
  set<int> criticalPoints;

  vector<bool> visited(N, false);
  vector<int> entryTime(N, -1), low(N, -1);
  int timer = 0;

  function<void(int, int)> dfs = [&](int curr, int parent) {
    visited[curr] = true;
    entryTime[curr] = low[curr] = timer++;

    int childrenCount = 0;
    for (int child : adj[curr]) {
      if (child == parent)
        continue;
      if (visited[child]) {
        low[curr] = min(low[curr], entryTime[child]);
      } else {
        dfs(child, curr);
        low[curr] = min(low[curr], low[child]);
        if (low[child] >= entryTime[curr] && parent != NO_PARENT) {
          criticalPoints.insert(curr);
        }
        childrenCount++;
      }
    }
    if (parent == NO_PARENT && childrenCount > 1) {
      criticalPoints.insert(curr);
    }
  };

  for (int i = 0; i < N; ++i) {
    if (!visited[i]) {
      dfs(i, NO_PARENT);
    }
  }

  return criticalPoints;
}

int32_t main() {
  vector<vector<int>> adj1 = GetAdjacencyList({
    {3, 0},
    {0, 1},
    {1, 2},
    {0, 4},
    {4, 5},
    {2, 3},
    {5, 3}
  }, true);
  // assert(GetArticulationPoints(adj1).size() == 0);

  auto adj2 = GetAdjacencyList({
    {0, 1},
    {1, 2},
    {2, 3},
    {3, 0},
  }, true);
  auto criticalPoints2 = GetArticulationPoints(adj2);
  cout << "Critical Points: "; for (int x : criticalPoints2) cout << x << ' '; cout << '\n';
  
  
  int N, M;
  cin >> N >> M;
  vector<vector<int>> adj(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  auto criticalPoints = GetArticulationPoints(adj);
  cout << "Critical Points: "; for (int x : criticalPoints) cout << x << ' '; cout << '\n';

  
  return 0;
}