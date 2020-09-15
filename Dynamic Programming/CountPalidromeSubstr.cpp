#include <bits/stdc++.h>
using li = int64_t;
using namespace std;

int CountPalidromeSubstr(string str) {
  li n = str.length(), dp[n + 1][n + 1];
  bool palidromeDp[n][n];
  memset(dp, 0, sizeof(dp));
  memset(palidromeDp, false, sizeof(palidromeDp));

  // length = 1
  for (li i = 0; i < n; ++i) {
    palidromeDp[i][i] = true;
  }

  // length = 2
  for (li i = 0; i < n - 1; ++i) {
    if (str[i] == str[i + 1]) {
      palidromeDp[i][i + 1] = true;
      // count++;
      dp[i][i + 1] = 1;
    }
  }

  // length > 2
  for (li l = 3; l <= n; ++l) {
    for (li i = 0; (i + l - 1) < n; ++i) {
      li j = i + l - 1;
      if (palidromeDp[i + 1][j - 1] && str[i] == str[j]) {
        palidromeDp[i][j] = true;
        // count++;
      }

      if (palidromeDp[i][j]) {
        dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + 1;
      } else {
        dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
      }
    }
  }

  // return count;
  return dp[0][n - 1];
}

int main() {
  string str;
  cin >> str;
  cout << CountPalidromeSubstr(str) << '\n';
  return 0;
}