// https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/B
#include "../SegmentTree_RangeUpdate_PointQuery.hpp"
#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
  int n, m;
  scanf("%lld %lld", &n, &m);

  auto compare = [](pair<int, int> a, pair<int, int> b) {
    return (a.second > b.second) ? a : b;
  };
  // {value, timestamp}
  SegmentTree<pair<int, int>> st(n, {0, -1}, compare);
  for (int q = 0; q < m; ++q) {
    int t;
    scanf("%lld", &t);
    if (t == 1) {
      int l, r, v;
      scanf("%lld %lld %lld", &l, &r, &v);
      st.Update(l, r - 1, {v, q});
    } else {
      int i;
      scanf("%lld", &i);
      printf("%lld\n", st.Query(i).first);
    }
  }

  return 0;
}