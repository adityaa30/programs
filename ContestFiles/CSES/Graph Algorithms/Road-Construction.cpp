#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
  vector<int> parent, size;

public:
  DSU(int sz) {
    parent = vector<int>(sz + 1);
    size = vector<int>(sz + 1, 1);
    iota(parent.begin(), parent.end(), 0);
  }

  int Root(int x) {
    if (parent[x] != x) {
      parent[x] = Root(parent[x]);
    }
    return parent[x];
  }

  bool Union(int x, int y) {
    int r_x = Root(x), r_y = Root(y);

    if (r_x == r_y) {
      return false;
    } else if (size[r_x] < size[r_y]) {
      swap(x, y);
      swap(r_x, r_y);
    }

    parent[r_y] = r_x;
    size[r_x] += size[r_y];
    return true;
  }

  int Size(int x) { return size[Root(x)]; }
};

int32_t main() {
  int n, m;
  cin >> n >> m;

  DSU dsu(n + 1);
  int cnt = n, mx = 1;

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;

    if (dsu.Union(a, b)) {
      --cnt;
      mx = max({mx, dsu.Size(a), dsu.Size(b)});
    }

    cout << cnt << ' ' << mx << '\n';
  }

  return 0;
}