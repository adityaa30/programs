// adityaa30
#include "../../Segment Tree/SegmentTree.hpp"
#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int32_t main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<ll> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &a[i]);
  SegmentTree<ll> st(a, 0, [](ll x, ll y) { return x + y; });
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
      printf("%lld\n", st.Query(a - 1, b - 1));
    }
  }
  return 0;
}