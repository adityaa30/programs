// https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/D
#include "../SegmentTree.hpp"
#include <bits/stdc++.h>
using namespace std;

// Max value of array element
const int mxA = 40;
using Node = bitset<(mxA + 1)>;

void Solve() {
  int N, Q;
  cin >> N >> Q;
  vector<Node> A(N);
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    A[i].set(x, true);
  }
  Node neutral;
  SegmentTree<Node> st(A, neutral, [](Node &a, Node &b) { return (a | b); });

  for (int q = 0; q < Q; ++q) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      cout << st.Query(x - 1, y - 1).count() << '\n';
    } else {
      Node val;
      val.set(y, true);
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