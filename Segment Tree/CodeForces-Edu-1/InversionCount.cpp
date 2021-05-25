// https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/A
#include "SegmentTree.hpp"
#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve() {
  int N, x;
  cin >> N;
  SegmentTree<int> st(N + 1, 0, [](int x, int y) { return x + y; });

  for (int i = 0; i < N; ++i) {
    cin >> x;
    cout << st.Query(x, N) << ' ';
    st.Set(x, 1);
  }
  cout << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}