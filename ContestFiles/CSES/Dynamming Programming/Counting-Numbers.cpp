#include <bits/stdc++.h>
#define int long long int
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int Count(string n) {
  int sz = n.length();
  vector<vvi> dp(sz, vvi(10, vi(2, -1)));

  function<int(int, int, bool)> go = [&](int pos, int prev, bool tight) {
    if (pos == sz) {
      return 1LL;
    }

    int count = -1;
    if (prev != -1) {
      count = dp[pos][prev][tight];
    }

    if (count != -1) {
      return count;
    }

    count = 0;
    int bound = (tight ? (n[pos] - '0') : 9);
    for (int digit = 0; digit <= bound; ++digit) {
      if (digit != prev && !(prev == -1 && digit == 0)) {
        count += go(pos + 1, digit, tight && (digit == bound));
      }
    }

    if (prev != -1) {
      dp[pos][prev][tight] = count;
    }
    return count;
  };

  int total = 1;
  for (int i = 0; i < sz; ++i) {
    total += go(i, -1, i == 0);
  }

  return total;
}

int32_t main() {
  int a, b;
  cin >> a >> b;

  int ans = Count(to_string(b));
  if (a >= 1) {
    ans -= Count(to_string(a - 1));
  }

  cout << ans << '\n';

  return 0;
}
