#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int32_t main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int a[n];
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  long long int dp[n][m + 1];
  memset(dp, 0, sizeof(dp));
  dp[0][a[0]] = 1;
  for (int j = 0; j <= m && a[0] == 0; ++j) {
    dp[0][j] = 1;
  }

  for (int i = 1; i < n; ++i) {
    if (a[i] != 0) {
      dp[i][a[i]] = dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1];
      dp[i][a[i]] %= MOD;
    }

    for (int j = 1; j <= m && a[i] == 0; ++j) {
      dp[i][j] = dp[i - 1][j];
      if ((j - 1) >= 1) dp[i][j] += dp[i - 1][j - 1];
      if ((j + 1) <= m) dp[i][j] += dp[i - 1][j + 1];
      dp[i][j] %= MOD;
    }
  }

  long long int ans = 0;
  for (int j = 1; j <= m; ++j) {
    ans += dp[n - 1][j];
    ans %= MOD;
  }
  printf("%lld", ans);

  return 0;
}