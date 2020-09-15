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

int PosX[] = {0, 1, 0, -1, 1, 1, -1, -1};
int PosY[] = {1, 0, -1, 0, 1, -1, 1, -1};

struct Edge {
  int from, to, weight;

  Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
};

void BellmanFord(int V, int src, vector<Edge> &edges) {
  vector<int> distance(V, INT_MAX);
  distance[src] = 0;
  for (int i = 0; i < V - 1; ++i) {
    for (Edge &e : edges) {
      distance[e.to] = min(distance[e.to], distance[e.from] + e.weight);
    }
  }

  for (int i = 0; i < V - 1; ++i) {
    for (Edge &e : edges) {
      if (distance[e.from] != INT_MAX &&
          distance[e.from] + e.weight < distance[e.to]) {
        cout << "Found negative cycle\n";
        return;
      }
    }
  }

  print(distance);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  int V = 9;

  vector<Edge> edges;
  edges.push_back(Edge(0, 1, -1));
  edges.push_back(Edge(0, 2, 4));
  edges.push_back(Edge(1, 2, 3));
  edges.push_back(Edge(1, 3, 2));
  edges.push_back(Edge(1, 4, 2));
  edges.push_back(Edge(3, 2, 5));
  edges.push_back(Edge(3, 1, 1));
  edges.push_back(Edge(4, 3, -3));

  BellmanFord(5, 0, edges);

  return 0;
}