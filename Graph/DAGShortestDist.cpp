// adityaa30
#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

stack<int> TopoSort(vector<vector<array<int, 2>>> &adj) {
  int V = adj.size();
  vector<bool> visited(V, false);

  bool isCycle = false;
  stack<int> s;
  function<void(int)> dfs = [&](int curr) {
    visited[curr] = true;
    for (array<int, 2> child : adj[curr]) {
      if (!visited[child[0]]) {
        dfs(child[0]);
      }
    }
    s.push(curr);
  };

  for (int i = 0; i < V; ++i) {
    if (!visited[i])
      dfs(i);
  }

  return s;
}

vector<int> DAGShortestDist(int src, vector<vector<array<int, 2>>> &adj) {
  int V = adj.size();
  vector<int> distance(V, INF);

  stack<int> topo = TopoSort(adj);
  distance[src] = 0;
  while (!topo.empty()) {
    int top = topo.top(); topo.pop();
    for (array<int, 2> child : adj[top]) {
      distance[child[0]] = min(distance[child[0]], distance[top] + child.back());
    }
  }

  return distance;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);
  int V = 6;
  vector<vector<array<int, 2>>> adj(V);

  function<void(int, int, int)> addEdge = [&](int a, int b, int weight) {
    adj[a].push_back({b, weight});
  };

  addEdge(0, 1, 5);
  addEdge(0, 2, 3);
  addEdge(1, 3, 6);
  addEdge(1, 2, 2);
  addEdge(2, 4, 4);
  addEdge(2, 5, 2);
  addEdge(2, 3, 7);
  addEdge(3, 4, -1);
  addEdge(4, 5, -2);

  DAGShortestDist(1, adj);

  return 0;
}