#include "LazySegmentTree.hpp"
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;

  LazySegmentTree<int> st(
      n, 0, [](int a, int b) { return (a > b ? a : b); }, 0,
      [](int a, int b, int len) { return a + b; });

  int l, r, v;

  function<int(int, int, int)> Get = [&](int x, int lx, int rx) {
    if (lx == rx) {
      return lx;
    }
    st.Propagate(x, lx, rx);
    int m = lx + (rx - lx) / 2;
    int res = -1;
    if (res == -1 && v <= st[(x << 1) + 1] && l <= m) {
      res = Get((x << 1) + 1, lx, m);
    }
    if (res == -1 && v <= st[(x << 1) + 2] && l <= rx) {
      res = Get((x << 1) + 2, m + 1, rx);
    }
    return res;
  };

  for (int q = 0; q < m; ++q) {
    int t;
    cin >> t;

    if (t == 1) {
      cin >> l >> r >> v;
      st.Update(l, r - 1, v);
    } else {
      cin >> v >> l;
      cout << Get(0, 0, st.Size() - 1) << '\n';
    }
  }

  return 0;
}