#include <bits/stdc++.h>
using namespace std;

const int NO_PARENT = -100;
int32_t main() {
  int n, x;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; ++i) {
    cin >> x;
    --x;
    adj[i].push_back(x);
    adj[x].push_back(i);
  }
  vector<int> subSize(n, 0);

  function<int(int, int)> dfs = [&](int curr, int parent) {
    int sz = 0;
    for (int child : adj[curr]) {
      if (child != parent) {
        sz += dfs(child, curr);
      }
    }
    subSize[curr] = sz;
    return sz + 1;
  };
  dfs(0, NO_PARENT);

  for (int sz : subSize) cout << sz << ' ';
  return 0;
}