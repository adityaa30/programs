// https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/C
#include "../SegmentTree.hpp"
#include <bits/stdc++.h>
using namespace std;

void Solve() {
  int N, foo;
  cin >> N;
  vector<int> left(N, -1);
  SegmentTree<int> st(2 * N + 1, 0, [](int x, int y) { return x + y; });
  vector<int> ans(N, 0);
  for (int i = 0; i < 2 * N; ++i) {
    cin >> foo;
    foo--;
    if (left[foo] == -1) {
      left[foo] = i;
    } else {
      ans[foo] = st.Query(left[foo], i);
      st.Set(left[foo], 1);
    }
  }

  for (int x : ans)
    cout << x << ' ';
  cout << '\n';
}

int32_t main() {
  Solve();
  return 0;
}