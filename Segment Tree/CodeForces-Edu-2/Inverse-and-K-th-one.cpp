// https://codeforces.com/edu/course/2/lesson/5/3/practice/contest/280799/problem/B
#include "../LazySegmentTree.hpp"
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
  int n, m;
  cin >> n >> m;

  const int NO_OP = -1000;

  LazySegmentTree<int> st(
      n, 0, [](int a, int b) { return a + b; }, NO_OP,
      [](int a, int b, int len) {
        if (b == NO_OP) {
          return a;
        }
        return len - a;
      });

  for (int q = 0; q < m; ++q) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r;
      cin >> l >> r;

      // No need to specify any value
      // the UpdateMergeType() passed to LazySegmentTree will handle
      // the updates. 
      st.Update(l, r - 1, 0);
    } else {
      int k;
      cin >> k;
      k += 1; // ones are numbered from 0
      int x = 0, lx = 0, rx = st.Size() - 1;
      while (lx < rx) {
        st.Propagate(x, lx, rx);
        int m = lx + (rx - lx) / 2;
        int left = st[2 * x + 1];
        if (k <= left) {
          rx = m;
          x = 2 * x + 1;
        } else {
          lx = m + 1;
          k -= left;
          x = 2 * x + 2;
        }
      }

      assert(k == 1);
      assert(lx == rx);
      cout << lx << '\n';
    }
  }

  return 0;
}