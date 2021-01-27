#include <bits/stdc++.h>
using namespace std;

const int NO_PARENT = -1;

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
  int mxDepth = 0, farthest = -1;
  function<void(int, int, int)> dfs = [&](int curr, int parent, int depth) {
    if (depth > mxDepth) {
      mxDepth = depth;
      farthest = curr;
    }

    for (int child : adj[curr]) {
      if (child != parent) {
        dfs(child, curr, depth + 1);
      }
    }
  };

  dfs(0, NO_PARENT, 0);
  dfs(farthest, NO_PARENT, 0);
  cout << mxDepth << '\n';

  return 0;
}