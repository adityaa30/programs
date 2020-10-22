// https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/A
#include "../SegmentTree.hpp"
#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve() {
  int N, Q;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    if (i & 1) A[i] = -A[i];
  }
  SegmentTree<int> st(A, 0, [](int x, int y) { return x + y; });
  cin >> Q;
  for (int q = 0; q < Q; ++q) {
    int t;
    cin >> t;
    if (t == 0) {
      int idx, val;
      cin >> idx >> val;
      --idx;
      if (idx & 1) val = -val;
      st.Set(idx, val);
    } else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      int ans = st.Query(l, r);
      if (l & 1) ans = -ans;
      cout << ans << '\n';
    }
  }
}

int32_t main() {
  Solve();
  return 0;
}