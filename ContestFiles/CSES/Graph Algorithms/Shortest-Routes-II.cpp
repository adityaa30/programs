#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<ll>> adj_slow(n + 1, vector<ll>(n + 1, INF));

  for (int i = 0; i < m; ++i) {
    int a, b;
    ll c;
    cin >> a >> b >> c;

    adj_slow[a][b] = min(adj_slow[a][b], c);
    adj_slow[b][a] = min(adj_slow[b][a], c);
  }

  vector<vector<pair<int, ll>>> adj(n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i != j && adj_slow[i][j] < INF) {
        adj[i].push_back({j, adj_slow[i][j]});
      }
    }
  }

  auto Dijkstra = [&](int start) {
    vector<ll> D(n + 1, INF);
    vector<bool> done(n + 1, false);
    priority_queue<pair<ll, ll>> q;

    q.push({0, start});
    D[start] = 0;
    while (!q.empty()) {
      ll curr = q.top().second;
      q.pop();

      if (done[curr]) {
        continue;
      }
      done[curr] = true;

      for (auto [child, w] : adj[curr]) {
        if (D[child] > D[curr] + w) {
          D[child] = D[curr] + w;
          q.push({-D[child], child});
        }
      }
    }

    return D;
  };

  vector<vector<ll>> dist(n + 1);
  for (int i = 1; i <= n; ++i) {
    dist[i] = Dijkstra(i);
  }

  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    cout << (dist[a][b] == INF ? -1 : dist[a][b]) << '\n';
  }
}
