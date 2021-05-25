// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B
#include "SegmentTree.hpp"
#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve(int test) {
  int N, M;
  cin >> N >> M;
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  SegmentTree<int> st(arr, LLONG_MAX, [](int x, int y) { return min(x, y); });
  for (int query = 1; query <= M; ++query) {
    int op;
    cin >> op;
    if (op == 1) {
      int idx, val;
      cin >> idx >> val;
      st.Set(idx, val);
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.Query(l, r - 1) << '\n';
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