// adityaa30
#include <bits/stdc++.h>
#define int long long int
#define debug(a) cout << #a << "=" << a << ' ';
#define print(it)                                                              \
  cout << #it << " -> ";                                                       \
  for (auto __x__ : it)                                                        \
    cout << __x__ << ' ';                                                      \
  cout << '\n';
using namespace std;

const int MOD = 1000000007;

int PosX[] = {0, 1, 0, -1};
int PosY[] = {1, 0, -1, 0};

struct Pair {
  int weight, idx;

  Pair(int weight, int idx) : weight(weight), idx(idx) {}
};

stack<int> TopoSort(vector<vector<Pair>> &adj) {
  int V = adj.size();
  vector<bool> visited(V, false);

  bool isCycle = false;
  stack<int> s;
  function<void(int)> Util = [&](int curr) {
    visited[curr] = true;
    for (Pair child : adj[curr]) {
      if (!visited[child.idx]) {
        Util(child.idx);
      }
    }
    s.push(curr);
  };

  for (int i = 0; i < V; ++i) {
    if (!visited[i])
      Util(i);
  }

  return s;
}

void DAGShortestDist(int src, vector<vector<Pair>> &adj) {
  int V = adj.size();
  vector<int> distance(V, INT_MAX);

  stack<int> topo = TopoSort(adj);
  distance[src] = 0;
  while (!topo.empty()) {
    int top = topo.top(); topo.pop();
    for (Pair child : adj[top]) {
      distance[child.idx] = min(distance[child.idx], distance[top] + child.weight);
    }
  }

  print(distance);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);
  int V = 6;
  vector<vector<Pair>> adj(V);

  function<void(int, int, int)> addEdge = [&](int a, int b, int weight) {
    adj[a].push_back(Pair(weight, b));
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