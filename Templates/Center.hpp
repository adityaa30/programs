#include <bits/stdc++.h>
using namespace std;

vector<int> GetTreeCenters(vector<vector<int>> &adj) {
  int n = (int)adj.size(); // 0-Indexed Undirected Tree

  vector<bool> visited(n, false);
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (adj[i].size() == 1)
      q.push(i);
  }
  while (!q.empty()) {
    int sz = q.size();
    if (sz <= 2) break; // atmost we can have only 2 center
    for (int i = 0; i < sz; ++i) {
      int curr = q.front(); q.pop();
      visited[curr] = true;
      for (int child : adj[curr]) {
        if (!visited[child]) q.push(child);
      }
    }
  }

  vector<int> centers;
  while (!q.empty()) {
    centers.push_back(q.front());
    q.pop();
  }
  return centers;
}
