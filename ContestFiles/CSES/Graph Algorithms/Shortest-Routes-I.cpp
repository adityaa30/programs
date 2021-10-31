#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> adj(n + 1);

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  auto Dijkstra = [&](int start) {
    vector<ll> D(n + 1, 1e18);
    vector<bool> done(n + 1, false);
    priority_queue<pair<ll, ll>> q;

    q.push({0, 1});
    D[1] = 0;
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

  auto ans = Dijkstra(1);

  for (ll i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}
