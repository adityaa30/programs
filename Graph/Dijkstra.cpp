// adityaa30
#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MOD = 1e7 + 5;
const int INF = INT_MAX;

vector<int> Dijkstra(vector<vector<array<int, 2>>> &adj, int src = 0) {
  // adj[x] -> List of {to, weight} # Weight should always be the `back()` value 
  
  int V = adj.size(); // 0-Indexed
  vector<int> distance(V, INF);
  using pii = pair<int, int>;
  priority_queue<pii, vector<pii>, greater<pii>> pq; // MinHeap

  distance[src] = 0;
  pq.push({0, src});

  while (!pq.empty()) {
    pii top = pq.top();
    pq.pop();
    int idx = top.second;
    for (auto child : adj[idx]) {
      int childWeight = child.back(), childIdx = child[0];
      if (distance[idx] + childWeight < distance[childIdx]) {
        distance[childIdx] = distance[idx] + childWeight;
        pq.push({distance[childIdx], childIdx});
      }
    }
  }

  return distance;
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

  cout << "Using STL O(NLogE): (source=0)\n";
  auto distance = Dijkstra(adj);
  for (int i = 0; i < (int) distance.size(); ++i) {
    cout << "Distance(" << i << ") = " << distance[i] << '\n';
  }

  return 0;
}