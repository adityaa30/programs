#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int INF = 1e18;

int32_t main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    --a, --b;
    adj[a].push_back({b, w});
  }

  vector<vector<int>> D(n, vector<int>(k, INF));

  int start = 0;
  D[start][0] = 0;
  priority_queue<pair<int, int>> pq;
  pq.push({D[start][0], start});

  while (!pq.empty()) {
    int curr = pq.top().second;
    int dist = -pq.top().first;
    pq.pop();

    if (D[curr][k - 1] < dist) {
      continue;
    }

    for (auto [child, w] : adj[curr]) {
      if (D[child][k - 1] > (dist + w)) {
        D[child][k - 1] = dist + w;
        pq.push({-D[child][k - 1], child});
        sort(D[child].begin(), D[child].end());
      }
    }
  }

  for (int i = 0; i < k; ++i) {
    cout << D[n - 1][i] << ' ';
  }
  cout << '\n';

  return 0;
}
