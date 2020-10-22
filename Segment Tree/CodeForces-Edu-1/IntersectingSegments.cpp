// https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/D
#include "../SegmentTree.hpp"
#include <bits/stdc++.h>
using namespace std;

void Solve() {
  int N, foo;
  cin >> N;
  vector<int> A(2 * N), ans(N, 0);
  for (int i = 0; i < 2 * N; ++i) cin >> A[i];
  
  for (int k = 0; k < 2; ++k) {
    SegmentTree<int> st(2 * N, 0, [](int x, int y) { return x + y; });
    vector<int> left(N, -1);
    for (int i = 0; i < 2 * N; ++i) {
      foo = A[i] - 1;
      if (left[foo] == -1) {
        left[foo] = i;
        st.Set(left[foo], 1);
      } else {
        st.Set(left[foo], 0);
        ans[foo] += st.Query(left[foo], i);
      }
    }
    reverse(A.begin(), A.end());
  }

  for (int x : ans)
    cout << x << ' ';
  cout << '\n';
}

int32_t main() {
  Solve();
  return 0;
}