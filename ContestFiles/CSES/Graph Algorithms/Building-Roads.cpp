#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
  vector<int> rank, parent;

public:
  DSU(int sz) {
    rank = vector<int>(sz + 1);
    parent = vector<int>(sz + 1);
    iota(parent.begin(), parent.end(), 0);
  }

  int root(int x) {
    if (parent[x] != x) {
      parent[x] = root(parent[x]);
    }
    return parent[x];
  }

  bool join(int x, int y) {
    int rx = root(x), ry = root(y);
    if (rx == ry) {
      return false;
    }

    if (rank[rx] == rank[ry]) {
      ++rank[rx];
    } else if (rank[rx] < rank[ry]) {
      swap(x, y);
      swap(rx, ry);
    }

    // rank[rx] > rank[ry]
    parent[ry] = rx;
    return true;
  }
};

int32_t main() {
  int n, m;
  cin >> n >> m;

  DSU dsu(n + 1);

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;

    dsu.join(a, b);
  }

  vector<pair<int, int>> ans;
  for (int i = 2; i <= n; ++i) {
    if (dsu.root(i) != dsu.root(i - 1)) {
      dsu.join(i, i - 1);
      ans.push_back({i - 1, i});
    }
  }

  cout << ans.size() << '\n';
  for (auto [a, b] : ans) {
    cout << a << ' ' << b << '\n';
  }

  return 0;
}
