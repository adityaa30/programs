#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
  int n;
  scanf("%lld", &n);
  int a[n], sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
    sum += a[i];
  }
  int dp[n][n];
  for (int l = n - 1; l >= 0; --l) {
    for (int r = l; r < n; ++r) {
      if (l == r) dp[l][r] = a[l];
      else dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
    }
  }
  printf("%lld", (sum + dp[0][n - 1]) / 2);
  return 0;
}