// https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/E
#include "SegmentTree.hpp"
#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve() {
  int N, Q;
  cin >> N >> Q;
  SegmentTree<int> st(N + 1, 0, [](int x, int y) { return x + y; });
  for (int q = 0; q < Q; ++q) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      r--;
      st.Set(l, st.Query(l) + v);
      st.Set(r + 1, st.Query(r + 1) - v);
    } else {
      int idx;
      cin >> idx;
      cout << st.Query(0, idx) << '\n';
    }
  }
}

int32_t main() {
  Solve();
  return 0;
}