// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/c
#include "../SegmentTree.hpp"
#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve(int test) {
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> arr(N, {0, 1});
  for (int i = 0; i < N; ++i) {
    cin >> arr[i].first;
  }

  auto Merge = [](pair<int, int> &x, pair<int, int> &y) {
    if (x.first == y.first) {
      return make_pair(x.first, x.second + y.second);
    } else if (x.first < y.first) {
      return x;
    } else {
      return y;
    }
  };

  SegmentTree<pair<int, int>> st(arr, {INT_MAX, 0}, Merge);
  for (int query = 1; query <= M; ++query) {
    int op;
    cin >> op;
    if (op == 1) {
      int idx, val;
      cin >> idx >> val;
      st.Set(idx, {val, 1});
    } else {
      int l, r;
      cin >> l >> r;
      pair<int, int> res = st.Query(l, r - 1);
      cout << res.first << ' ' << res.second << '\n';
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