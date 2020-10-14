#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int32_t main() {
  int n;
  scanf("%d", &n);
  int s = (n * (n + 1)) / 2;
  if (s & 1) printf("0\n");
  else {
    int target = s / 2;
    int dp[n + 1][target + 1];
    memset(dp, 0, sizeof(dp));
    for (int s = 0; s <= target; ++s) {
      for (int i = 1; i <= n; ++i) {
        if (s == 0) dp[i][s] = 1;
        else {
          dp[i][s] += dp[i - 1][s];
          if (s >= i) dp[i][s] += dp[i - 1][s - i];
          dp[i][s] %= MOD;
        }
      }
    }
    printf("%d", dp[n][target]);
  }
  return 0;
}