#include <bits/stdc++.h>
using namespace std;

const int NO_PARENT = -100;

int32_t main() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  function<array<int, 2>(int, int)> dfs = [&](int curr, int parent) {
    int with = 0, without = 0;
    vector<array<int, 2>> childRes;
    for (int child : adj[curr]) {
      if (child != parent) {
        childRes.push_back(dfs(child, curr));
      }
    }

    for (auto [cWith, cWithout] : childRes) {
      without += cWith;
    }

    for (auto [cWith, cWithout] : childRes) {
      with = max(with, 1 + without - cWith + cWithout);
    }

    return array<int, 2>{with, without};
  };


  array<int, 2> ans = dfs(0, NO_PARENT);
  cout << max(ans[0], ans[1]) << '\n';

  return 0;
}