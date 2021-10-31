// https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/B
#include "LazySegmentTree.hpp"
#include <bits/stdc++.h>
#define int long long int
using namespace std;

// 0011100011110000111000111

const int mL = (1 << 19) - 1;

struct Node {
  int cnt = 0, sum = 0, prefix = 0, suffix = 0;
  bool op = false;
};

int32_t main() {
  int n;
  cin >> n;

  // TODO: Giving WA
  Node neutral;
  LazySegmentTree<Node> st(
      mL, neutral,
      [](Node a, Node b) {
        Node res;
        res.sum = a.sum + b.sum;
        res.cnt = a.cnt + b.cnt;
        if (a.prefix == a.sum) {
          res.prefix = a.sum + b.prefix;
        } else {
          res.prefix = a.prefix;
        }

        if (b.suffix == b.sum) {
          res.suffix = a.suffix + b.sum;
        } else {
          res.suffix = b.suffix;
        }

        if (res.sum == res.prefix && res.sum == res.suffix &&
            res.prefix == res.suffix) {
          // Entire segment is black
        }
        if (res.prefix < a.sum && a.sum > 0) {
          // Black segment `a` in the mid
          res.cnt++;
        }

        if (res.suffix < b.sum && b.sum > 0) {
          // Black segment `b` in the mid
          res.cnt++;
        }

        return res;
      },
      neutral,
      [](Node a, Node b, int len) {
        if (!b.op)
          return a;
        return b;
      });

  char c;
  int x, l;
  for (int q = 0; q < n; ++q) {
    cin >> c >> x >> l;
    Node up;
    up.sum = (int)(c == 'B');
    up.prefix = up.sum;
    up.suffix = up.sum;
    up.op = true;
    st.Update(x, x + l - 1, up);

    Node ans = st.Query(0, mL - 1);
    if (ans.sum == ans.prefix && ans.sum == ans.suffix &&
        ans.prefix == ans.suffix) {
      ans.cnt++;
    } else {
      if (ans.prefix > 0)
        ++ans.cnt;
      if (ans.suffix > 0)
        ++ans.cnt;
    }
    cout << ans.cnt << ' ' << ans.sum << '\n';
  }
  return 0;
}