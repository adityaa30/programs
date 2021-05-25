// https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/A
#include <bits/stdc++.h>
#include "SegmentTree_RangeUpdate_PointQuery.hpp"
#define int long long int
using namespace std;

int32_t main() {
  int n, m;
  cin >> n >> m;

  SegmentTree<int> st(n, 0, [](int a, int b) { return a + b; });
  for (int q = 0; q < m; ++q) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      st.Update(l, r - 1, v);
    } else {
      int i;
      cin >> i;
      cout << st.Query(i) << '\n';
    }
  }

  return 0;
}