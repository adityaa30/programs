#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;

int32_t main() {
  int N;
  cin >> N;
  //   int dp[N + 1];
  //   dp[0] = 0;
  //   for (int i = 1; i <= N; ++i) {
  //     int curr = i;
  //     dp[i] = INT_MAX;
  //     while (curr != 0) {
  //       int d = curr % 10;
  //       curr /= 10;
  //       dp[i] = min(dp[i], 1 + dp[i - d]);
  //     }
  //   }

  //   cout << dp[N] << '\n';

  int ans = 0;
  while (N > 0) {
    ++ans;
    int mxD = 0;
    int curr = N;
    while (curr > 0) {
      mxD = max(mxD, curr % 10);
      curr /= 10;
    }
    N -= mxD;
  }

  cout << ans << '\n';

  return 0;
}