#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int mxS = 100 * 1000 + 5;

int32_t main() {
  int n;
  cin >> n;

  bitset<mxS> dp;
  dp[0] = 1;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    dp = dp | (dp << x);
  }

  cout << (dp.count() - 1) << '\n';
  for (int s = 1; s < mxS; ++s) {
    if (dp[s]) {
      cout << s << ' ';
    }
  }
  cout << '\n';

  return 0;
}
