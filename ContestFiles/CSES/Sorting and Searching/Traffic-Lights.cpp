#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int x, n, p;
  cin >> x >> n;

  multiset<int> s;
  set<int> bounds;
  bounds.insert(0);
  bounds.insert(x);
  s.insert(x);

  for (int i = 0; i < n; ++i) {
    cin >> p;
    auto it = bounds.upper_bound(p);
    assert(it != bounds.end());
    assert(it != bounds.begin());
    int d1 = *it - p;
    --it;
    int d2 = p - *it;
    bounds.insert(p);
    s.erase(s.find(d1 + d2));
    s.insert(d1);
    s.insert(d2);
    cout << *(--s.end()) << ' ';
  }
  return 0;
}