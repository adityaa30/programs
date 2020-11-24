#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> parent(n, -1);
  vector<bool> visited(n, false);
  array<int, 2> nodes = {-1, -1};
  function<void(int)> cycle = [&](int curr) {
    visited[curr] = true;
    for (int child : adj[curr]) {
      if (!visited[child]) {
        parent[child] = curr;
        cycle(child);
      } else if (child != parent[curr] && nodes[0] == -1) {
        nodes[0] = child;
        nodes[1] = curr;
      }
    }
  };
  cycle(0);
  assert(nodes[0] != -1 && nodes[1] != -1);

  vector<int> cPath;
  cPath.push_back(nodes[0]);
  int cx = nodes[1];
  while (cx != nodes[0]) {
    assert(cx != -1);
    cPath.push_back(cx);
    cx = parent[cx];
  }

  function<int(int)> GetSize = [&](int curr) {
    int sz = 1;
    visited[curr] = true;
    for (int child : adj[curr]) {
      if (!visited[child]) {
        sz += GetSize(child);
      }
    }
    return sz;
  };
  int count = n * (n - 1);
  fill(visited.begin(), visited.end(), false);
  for (int x : cPath) visited[x] = true;
  for (int x : cPath) {
    int s = GetSize(x);
    count -= (s * (s - 1)) / 2;
  }
  cout << count << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  int t = 1;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
    Solve();
  }

  return 0;
}