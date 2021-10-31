// https://codeforces.com/edu/course/2/lesson/5/3/practice/contest/280799/problem/A
#include "LazySegmentTree.hpp"
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Node {
  int sum = 0, prefix = 0, suffix = 0, mxSum = 0;
  bool op = true;
};

int32_t main() {
  int n, m;
  cin >> n >> m;

  Node queryNeutral, updateNeutral;
  updateNeutral.op = false;

  LazySegmentTree<Node> st(
      vector<Node>(n), queryNeutral,
      [](Node a, Node b) {
        Node n;
        n.sum = a.sum + b.sum;
        n.prefix = max({0LL, a.prefix, a.sum + b.prefix});
        n.suffix = max({0LL, b.suffix, a.suffix + b.sum});
        n.mxSum = max({0LL, a.mxSum, b.mxSum, a.suffix + b.prefix});
        return n;
      },
      updateNeutral,
      [](Node a, Node b, int len) {
        if (!b.op) {
          return a;
        }
        b.sum *= len;
        b.prefix *= len;
        b.suffix *= len;
        b.mxSum *= len;
        return b;
      });

  for (int q = 0; q < m; ++q) {
    int l, r, v;
    cin >> l >> r >> v;
    Node node;
    node.sum = v;
    node.prefix = max(0LL, v);
    node.suffix = max(0LL, v);
    node.mxSum = max(0LL, v);
    st.Update(l, r - 1, node);

    cout << st.Query(0, n - 1).mxSum << '\n';
  }

  return 0;
}
