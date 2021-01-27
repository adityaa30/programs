#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int n, x;
  cin >> n >> x;
  vector<int> P(n);
  for (int i = 0; i < n; ++i) cin >> P[i];
  sort(P.begin(), P.end());

  int count = 0;
  int i = 0, j = n - 1;
  while (i <= j) {
    if (P[i] + P[j] <= x) {
      ++count;
      ++i, --j;
    } else {
      --j, ++count;
    }
  }
  cout << count << '\n';
  return 0;
}