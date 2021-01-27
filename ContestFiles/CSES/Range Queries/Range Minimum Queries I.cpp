// adityaa30
#include "../../Segment Tree/SegmentTree.hpp"
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
  SegmentTree<int> st(arr, INT_MAX, [&](int x, int y) { return min(x, y); });
  while (q--) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld\n", st.Query(a - 1, b - 1));
  }
  return 0;
}