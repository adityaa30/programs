// https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/E
#include "../SegmentTree.hpp"
#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int INF = LLONG_MAX;

void Solve() {
  int N, Q;
  cin >> N >> Q;
  SegmentTree<int> st(N, INF, [](int a, int b) { return min(a, b); });

  function<int(int, int, int, int, int, int)> Find = [&](int l, int r, int p, int x, int lx, int rx) {
    if (r < lx || rx < l) {
      // [l...r lx...rx l...r]
      // Do not intersect
      return 0LL;
    } 
    if (lx == rx) {
      if (st[x] <= p) {
        st[x] = INF;
        return 1LL;
      }
      return 0LL;
    }

    int m = lx + (rx - lx) / 2;
    int res = 0;
    if (st[2 * x + 1] <= p) res += Find(l, r, p, 2 * x + 1, lx, m);
    if (st[2 * x + 2] <= p) res += Find(l, r, p, 2 * x + 2, m + 1, rx);
    
    st.MergeChildsOfNode(x);
    return res;
  };

  for (int q = 0; q < Q; ++q) {
    int t;
    cin >> t;
    if (t == 1) {
      int idx, h;
      cin >> idx >> h;
      st.Set(idx, h);
    } else if (t == 2) {
      int l, r, p;
      cin >> l >> r >> p;
      cout << Find(l, r - 1, p, 0, 0, st.Size() - 1) << '\n';
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