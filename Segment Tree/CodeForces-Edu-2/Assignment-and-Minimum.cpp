// https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/E
#include "LazySegmentTree.hpp"
#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
  int n, m;
  cin >> n >> m;
  const int NO_OP = -100;
  LazySegmentTree<int> st(
      vector<int>(n, 0), LLONG_MAX, [](int a, int b) { return min(a, b); },
      NO_OP,
      [](int a, int b, int len) {
        if (b == NO_OP)
          return a;
        return b;
      });

  for (int q = 0; q < m; ++q) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      st.Update(l, r - 1, v);
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.Query(l, r - 1) << '\n';
    }
  }

  return 0;
}