// https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/C
#include "../SegmentTree.hpp"
#include <bits/stdc++.h>
#define int long long int
using namespace std;

// Max value of array element
const int mxA = 40;

struct Node {
  int inv = 0;
  vector<int> cnt = vector<int>(1 + mxA, 0);
};

void Solve() {
  int N, Q;
  cin >> N >> Q;
  vector<Node> A(N);
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    A[i].cnt[x] = 1;
  }
  Node neutral;
  SegmentTree<Node> st(A, neutral, [](Node &a, Node &b) {
    Node res;
    res.inv = a.inv + b.inv;
    int big = 0;
    for (int i = mxA; i >= 0; --i) {
      res.cnt[i] = a.cnt[i] + b.cnt[i];
      res.inv += big * b.cnt[i];
      big += a.cnt[i];
    }
    return res;
  });

  for (int q = 0; q < Q; ++q) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      Node res = st.Query(x - 1, y - 1);
      cout << res.inv << '\n';
    } else {
      Node val;
      val.cnt[y] = 1;
      st.Set(x - 1, val);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  Solve();
  return 0;
}