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

  vector<int> D(n + 1, INF);
  vector<int> prev(n + 1, -1);

  queue<int> q;
  q.push(1);
  D[1] = 0;

  while (!q.empty()) {
    int x = q.front();
    q.pop();

    if (x == n) {
      break;
    }

    for (int child : adj[x]) {
      if (D[child] > (D[x] + 1)) {
        D[child] = D[x] + 1;
        prev[child] = x;
        q.push(child);
      }
    }
  }

  if (D[n] == INF) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  vector<int> route;
  int curr = n;
  while (curr != -1) {
    route.push_back(curr);
    curr = prev[curr];
  }
  reverse(route.begin(), route.end());

  cout << route.size() << '\n';
  for (int x : route) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}
