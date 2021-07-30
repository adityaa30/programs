// https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/A
#include "../LazySegmentTree.hpp"
#include <bits/stdc++.h>
#define int long long int
using namespace std;

struct Node {
  int val = 0;
  int type = -1; // Nothing

  string str() {
    return "{val=" + to_string(val) + ", type=" + to_string(type) + "}";
  }
};

int32_t main() {
  int n, m, t, l, r, v;
  cin >> n >> m;

  Node neutral;

  LazySegmentTree<Node> st(
      n, neutral,
      [](Node a, Node b) {
        Node res;
        res.val = a.val + b.val;
        return res;
      },
      neutral,
      [](Node a, Node b, int len) {
        Node res = a;
        if (b.type == 1) {
          res.type = b.type;
          res.val = b.val * len;
        } else if (b.type == 2) {
          res.type = b.type;
          if (a.type == 1) res.type = 1;
          res.val += b.val * len;
        } 

        return res;
      });

  for (int q = 0; q < m; ++q) {
    cin >> t;
    if (t <= 2) {
      cin >> l >> r >> v;
      Node up;
      up.val = v;
      up.type = t;
      st.Update(l, r - 1, up);
    } else {
      cin >> l >> r;
      cout << st.Query(l, r - 1).val << '\n';
    }
  }

  return 0;
}