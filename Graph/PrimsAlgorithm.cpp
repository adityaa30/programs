// adityaa30
#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int MOD = 1e9 + 7;


vector<int> PrimsMST(vector<vector<array<int, 2>>> &adj, int src = 0) {
  // adj[x] -> List of {to, weight} # Weight should always be the `back()` value 
  
  int V = adj.size(); // 0-indexed
  vector<bool> visited(V, false);
  vector<int> weights(V, INF), parent(V, -1);

  using pii = pair<int, int>;
  priority_queue<pii, vector<pii>, greater<pii>> pq;

  weights[src] = 0;
  pq.push({0, src}); // (distance, node)

  while (!pq.empty()) {
    pii top = pq.top(); // get the edge with minimum weight
    pq.pop();
    int idx = top.second;
    visited[idx] = true;
    for (auto child : adj[idx]) {
      int childWeight = child.back(), childIdx = child[0];
      if (!visited[childIdx] && childWeight < weights[childIdx]) {
        weights[childIdx] = childWeight;
        pq.push({childWeight, childIdx});
        parent[childIdx] = idx;
      }
    }
  }

  return parent;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  int V = 9;
  vector<vector<array<int, 2>>> adj(V);

  function<void(int, int, int)> addEdge = [&](int a, int b, int weight) {
    adj[a].push_back({b, weight});
    adj[b].push_back({a, weight});
  };

  addEdge(0, 1, 4);
  addEdge(0, 7, 8);
  addEdge(1, 2, 8);
  addEdge(1, 7, 11);
  addEdge(2, 3, 7);
  addEdge(2, 8, 2);
  addEdge(2, 5, 4);
  addEdge(3, 4, 9);
  addEdge(3, 5, 14);
  addEdge(4, 5, 10);
  addEdge(5, 6, 2);
  addEdge(6, 7, 1);
  addEdge(6, 8, 6);
  addEdge(7, 8, 7);

  auto parent = PrimsMST(adj, 0);
  for (int i = 1; i < (int) parent.size(); ++i) {
    cout << i << " <-> " << parent[i] << '\n';
  }
  return 0;
}