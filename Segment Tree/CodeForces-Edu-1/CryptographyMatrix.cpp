// https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/B
#include "../SegmentTree.hpp"
#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve() {
  int R, N, M;
  cin >> R >> N >> M;
  using Matrix = array<int, 4>;
  vector<Matrix> A(N);
  for (int i = 0; i < N; ++i) {
    for (int k = 0; k < 4; ++k) {
      cin >> A[i][k];
      A[i][k] %= R;
    }
  }
  Matrix identity = {1, 0, 0, 1};
  SegmentTree<Matrix> st(A, identity, [&](Matrix &a, Matrix &b) {
    Matrix res = {
        (a[0] * b[0] + a[1] * b[2]) % R, (a[0] * b[1] + a[1] * b[3]) % R,
        (a[2] * b[0] + a[3] * b[2]) % R, (a[2] * b[1] + a[3] * b[3]) % R};
    return res;
  });
  for (int q = 0; q < M; ++q) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    Matrix ans = st.Query(l, r);
    cout << ans[0] << ' ' << ans[1] << '\n'
         << ans[2] << ' ' << ans[3] << "\n\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  Solve();
  return 0;
}