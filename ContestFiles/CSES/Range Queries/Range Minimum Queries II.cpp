// adityaa30
#include "../../Segment Tree/SegmentTree.hpp"
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  SegmentTree<int> st(a, INT_MAX, [](int x, int y) { return min(x, y); });
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int k, u;
      scanf("%d %d", &k, &u);
      st.Set(k - 1, u);
    } else {
      int a, b;
      scanf("%d %d", &a, &b);
      printf("%d\n", st.Query(a - 1, b - 1));
    }
  }
  return 0;
}