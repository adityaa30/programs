#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int INF = 1e18;

int32_t main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n), rev_adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    --a, --b;
    adj[a].push_back({b, w});
    rev_adj[b].push_back({a, w});
  }

  auto Dijkstra = [&](vector<vector<pair<int, int>>> &graph, int start) {
    priority_queue<pair<int, int>> pq;
    vector<int> D(n, INF);
    vector<bool> done(n, false);

    D[start] = 0;
    pq.push({D[start], start});

    while (!pq.empty()) {
      int curr = pq.top().second;
      pq.pop();

      if (done[curr]) {
        continue;
      }

      done[curr] = true;

      for (auto [child, w] : graph[curr]) {
        if (D[child] > (D[curr] + w)) {
          D[child] = D[curr] + w;
          pq.push({-D[child], child});
        }
      }
    }

    return D;
  };

  vector<int> from_1 = Dijkstra(adj, 0);
  vector<int> from_n = Dijkstra(rev_adj, n - 1);

  int ans = INF;
  for (int from = 0; from < n; ++from) {
    for (auto [to, w] : adj[from]) {
      int v = from_1[from] + (w / 2) + from_n[to];
      ans = min(ans, v);
    }
  }

  cout << ans << '\n';

  return 0;
}
