#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int32_t main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  for (int i = 1; i <= m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> team(n + 1, -1);

  auto bipartite = [&](int start) {
    queue<int> q;
    q.push(start);
    team[start] = 1;

    while (!q.empty()) {
      int prev = q.front();
      q.pop();

      for (int nxt : adj[prev]) {
        if (team[nxt] == -1) {
          team[nxt] = (team[prev] == 1) ? 2 : 1;
          q.push(nxt);
        } else if (team[nxt] == team[prev]) {
          return false;
        }
      }
    }

    return true;
  };

  for (int i = 1; i <= n; ++i) {
    if (team[i] == -1 && !bipartite(i)) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << team[i] << ' ';
  }
  cout << "\n";

  return 0;
}
