// https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/B
#include "../LazySegmentTree.hpp"
#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
  int n, m;
  cin >> n >> m;

  // Keep array A -> A0, A1 - A0, A2 - A1, ... An - An-1
  // Original Ai = Sum(A0 ... Ai)

  LazySegmentTree<int> st(
      n + 2, 0, [](int a, int b) { return a + b; }, 0,
      [](int a, int b, int len) { return a + b * len; });

  for (int q = 0; q < m; ++q) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, a, d;
      cin >> l >> r >> a >> d;
      st.Update(l, a);
      if (l + 1 <= r) {
        st.Update(l + 1, r, d);
      }
      st.Update(r + 1, -(a + d * (r - l)));
    } else {
      int x;
      cin >> x;
      cout << st.Query(0, x) << '\n';
    }
  }

  return 0;
}