// https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/D
#include "../LazySegmentTree.hpp"
#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
  int n, m;
  cin >> n >> m;
  LazySegmentTree<int> st(
      vector<int>(n, 0), 0LL, [](int a, int b) { return a + b; }, 0LL,
      [](int a, int b, int len) { return a + b * len; });

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