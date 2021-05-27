// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B
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
  SegmentTree<int> st(arr, 0, [](int x, int y) { return x + y; });
  for (int query = 1; query <= M; ++query) {
    int op, x;
    cin >> op >> x;
    if (op == 1) {
      st.Set(x, st.Query(x) ^ 1);
    } else {
      x += 1;
      int idx = 0, lx = 0, rx = st.Size() - 1;
      while (lx < rx) {
        int m = lx + (rx - lx) / 2;
        int left = st[2 * idx + 1];
        int right = st[2 * idx + 2];
        if (x <= left) {
          rx = m;
          idx = 2 * idx + 1;
        } else {
          lx = m + 1;
          x -= left;
          idx = 2 * idx + 2;
        }
      }
      assert(x == 1);
      assert(lx == rx);
      cout << rx << '\n';
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