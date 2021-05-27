// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/D
#include "SegmentTree.hpp"
#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve(int test) {
  int N, M;
  cin >> N >> M;
  vector<int> arr(N, 0);
  for (int i = 0; i < N; ++i)
    cin >> arr[i];
  SegmentTree<int> st(arr, -1, [](int x, int y) { return max(x, y); });
  for (int query = 1; query <= M; ++query) {
    int op;
    cin >> op;
    if (op == 1) {
      int idx, val;
      cin >> idx >> val;
      st.Set(idx, val);
    } else {
      int X, L;
      cin >> X >> L;
      function<int(int, int, int)> find = [&](int x, int lx, int rx) {
        if (st[x] < X || L > rx)
          return -1LL;
        if (lx == rx)
          return lx;
        int m = lx + (rx - lx) / 2;
        int res = find(2 * x + 1, lx, m);
        if (res == -1)
          res = find(2 * x + 2, m + 1, rx);
        return res;
      };
      cout << find(0, 0, st.Size() - 1) << '\n';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  //   cin >> t;
  for (int test = 1; test <= t; ++test) {
    Solve(test);
  }

  return 0;
}