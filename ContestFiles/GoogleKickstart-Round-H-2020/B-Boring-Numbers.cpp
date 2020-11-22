#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve(int test) {
  int L, R;
  cin >> L >> R;

  auto DigitDp = [&](int val) {
    if (val == 0) return 0LL;
    string nStr = to_string(val);
    int len = nStr.length();
    vector<array<int, 2>> dp(len, {-1, -1});
    function<int(int, bool)> solver = [&](int digit, bool match) {
      if (digit >= len) return 1LL;
      int &ans = dp[digit][match];
      if (ans != -1) return ans;

      ans = 0;
      for (int d = !(digit % 2); d < 10; d += 2) {
        if (d <= (nStr[digit] - '0') || !match) {
          ans += solver(digit + 1, match && d == (nStr[digit] - '0'));
        }
      }

      return ans;
    };

    int total = 0;
    for (int i = 0; i < len; ++i) {
      total += solver(i, i == 0);
    }

    return total;
  };

  int res = DigitDp(R) - DigitDp(L - 1);
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  int t = 1;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
    cout << "Case #" << test << ": ";
    Solve(test);
  }

  return 0;
}