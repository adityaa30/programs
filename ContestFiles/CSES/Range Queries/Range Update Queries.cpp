// adityaa30
#include "SegmentTree.hpp"
#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

int32_t main() {
  int n, q;
  scanf("%d %d", &n, &q);
  SegmentTree<ll> st(n + 1, 0, [](ll x, ll y) { return x + y; });
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    st.Set(i, st.Query(i) + a);
    st.Set(i + 1, st.Query(i + 1) - a);
  }
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int a, b, u;
      scanf("%d %d %d", &a, &b, &u);
      st.Set(a - 1, st.Query(a - 1) + u);
      st.Set(b, st.Query(b) - u);
    } else {
      int k;
      scanf("%d", &k);
      printf("%lld\n", st.Query(0, k - 1));
    }
  }
  return 0;
}