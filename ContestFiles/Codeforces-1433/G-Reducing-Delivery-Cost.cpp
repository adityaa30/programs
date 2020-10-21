#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int INF = LLONG_MAX;

struct Edge {
  int weight, from, to;

  Edge(int weight, int from, int to) : weight(weight), from(from), to(to) {}
};

vector<int> Dijkstra(vector<vector<Edge>> &adj, int src) {
  int V = adj.size();
  vector<int> distance(V, INF);
  using pi = pair<int, int>;
  priority_queue<int, vector<pi>, greater<pi>> pq; 

  distance[src] = 0;
  pq.push({0, src});

  while (!pq.empty()) {
    pi top = pq.top();
    pq.pop();
    int weight = top.first, idx = top.second;
    for (Edge child : adj[idx]) {
      if (distance[idx] + child.weight < distance[child.to]) {
        distance[child.to] = distance[idx] + child.weight;
        pq.push({distance[child.to], child.to});
      }
    }
  }

  return distance;
}

void Solve() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<Edge>> adj(N);
  for (int i = 0; i < M; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    --x, --y;
    adj[x].push_back({w, x, y});
    adj[y].push_back({w, y, x});
  }
  vector<vector<int>> D(N);
  for (int src = 0; src < N; ++src) {
    D[src] = Dijkstra(adj, src);
  }

  vector<array<int, 2>> routes(K);
  for (int i = 0; i < K; ++i) {
    cin >> routes[i][0] >> routes[i][1];
    routes[i][0]--, routes[i][1]--;
  }

  int ans = INF;
  for (int from = 0; from < N; ++from) {
    for (Edge edge : adj[from]) {
      int curr = 0, to = edge.to;
      for (int i = 0; i < K; ++i) {
        int a = routes[i][0], b = routes[i][1];
        curr += min({D[a][b], D[a][from] + D[to][b], D[a][to] + D[from][b]});
      }
      ans = min(ans, curr);
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);
  Solve();

  return 0;
}