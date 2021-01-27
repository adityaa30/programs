#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int n, m;
  cin >> n >> m;
  map<int, int> count;
  for (int i = 0; i < n; ++i)  {
    int x;
    cin >> x;
    count[x] += 1;
  }
 
  for (int q = 0; q < m; ++q) {
    int mx;
    cin >> mx;
    if (count.empty()) {
      cout << "-1\n";
      continue;
    }

    auto it = count.lower_bound(mx);
    if (it == count.begin() && it->first > mx) {
      cout << "-1\n";
      continue;
    }

    if (it->first > mx) it--;
    int x = it->first;

    cout << x << '\n';

    if (count[x] == 1) {
      count.erase(x);
    } else {
      count[x]--;
    }
  }

  return 0;
}