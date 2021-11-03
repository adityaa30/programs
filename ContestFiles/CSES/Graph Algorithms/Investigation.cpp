#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int INF = 1e18;
const int MOD = 1e9 + 7;

int32_t main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    --a, --b;
    adj[a].push_back({b, w});
  }

  int start = 0;
  vector<int> D(n, INF), cnt(n, 0), mx_cnt(n, -INF), mn_cnt(n, INF);
  priority_queue<pair<int, int>> pq;

  D[start] = 0;
  cnt[start] = 1;
  mx_cnt[start] = mn_cnt[start] = 0;
  pq.push({-D[start], start});

  while (!pq.empty()) {
    auto [d, curr] = pq.top();
    pq.pop();

    if (D[curr] < abs(d)) {
      continue;
    }

    for (auto [child, w] : adj[curr]) {
      if (D[child] > (D[curr] + w)) {
        cnt[child] = cnt[curr];
        D[child] = D[curr] + w;
        mn_cnt[child] = mn_cnt[curr] + 1;
        mx_cnt[child] = mx_cnt[curr] + 1;
        pq.push({-D[child], child});
      } else if (D[child] == (D[curr] + w)) {
        cnt[child] += cnt[curr];
        mn_cnt[child] = min(mn_cnt[child], mn_cnt[curr] + 1);
        mx_cnt[child] = max(mx_cnt[child], mx_cnt[curr] + 1);
      }

      cnt[child] %= MOD;
    }
  }

  cout << D[n - 1] << ' ' << cnt[n - 1] << ' ' << mn_cnt[n - 1] << ' '
       << mx_cnt[n - 1] << '\n';

  return 0;
}
