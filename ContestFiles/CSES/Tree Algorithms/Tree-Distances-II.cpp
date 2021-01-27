#include <bits/stdc++.h>
using namespace std;

const int NO_PARENT = -100;
int32_t main() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> distances(n, 0);
  function<int(int, int, int)> updateDepths = [&](int curr, int parent, int depth) {
    int mx = depth;
    for (int child : adj[curr]) {
      if (child != parent) {
        mx = max(mx, updateDepths(child, curr, depth + 1));
      }
    }
    distances[curr] = mx - depth;
    return mx;
  };

  updateDepths(0, NO_PARENT, 0);

  function<void(int, int, int)> dfs = [&](int curr, int parent, int fromParent) {
    int sz = adj[curr].size();
    vector<int> pMx(sz), sMx(sz);
    distances[curr] = max(distances[curr], 1 + fromParent);
    for (int i = 0; i < sz; ++i) {
      pMx[i] = max((i ? pMx[i - 1] : 0), distances[adj[curr][i]]);
    }
    for (int i = sz - 1; i >= 0; --i) {
      sMx[i] = max((i == sz - 1 ? 0 : sMx[i + 1]), distances[adj[curr][i]]);
    }

    for (int i = 0; i < sz; ++i) {
      int child = adj[curr][i];
      if (child != parent) {
        int other = max((i ? pMx[i - 1] : 0), (i == sz - 1 ? 0 : sMx[i + 1]));
        dfs(child, curr, other);
      }
    }

  };

  dfs(0, NO_PARENT, -1);

  for (int x : distances) {
    cout << x << ' ';
  }
  
  return 0;
}