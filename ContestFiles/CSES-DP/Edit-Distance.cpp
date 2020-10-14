#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int32_t main() {
  string s, t;
  cin >> s;
  cin >> t;
  const int n = s.length(), m = t.length();

  int dp[n + 1][m + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (i == 0 && j == 0) continue;
      dp[i][j] = INF;
      // add, remove, replace
      if (j >= 1) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
      if (i >= 1) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
      if (i >= 1 && j >= 1) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
    }
  }
  cout << dp[n][m] << '\n';
}