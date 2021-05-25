// https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/B
#include "SegmentTree.hpp"
#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve() {
  int N;
  cin >> N;
  vector<int> arr;
  arr.assign(N, 1);
  SegmentTree<int> st(arr, 0LL, [](int x, int y) { return x + y; });

  function<int(int, int, int, int)> Find = [&](int val, int x, int lx, int rx) {
    if (lx == rx)
      return (st[x] == 1 ? lx : -1);

    int right = st[2 * x + 2];
    int m = lx + (rx - lx) / 2;
    if (val < right) {
      return Find(val, 2 * x + 2, m + 1, rx);
    }
    return Find(val - right, 2 * x + 1, lx, m);
  };

  vector<int> ans(N), inv(N);
  for (int i = 0; i < N; ++i) {
    cin >> inv[i];
  }

  for (int i = N - 1; i >= 0; --i) {
    int idx = Find(inv[i], 0, 0, st.Size() - 1);
    assert(idx >= 0);
    ans[i] = idx + 1;
    st.Set(idx, 0);
  }

  for (int x : ans)
    cout << x << ' ';
  cout << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}