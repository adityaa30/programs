#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int N;
  cin >> N;
  vector<int> dp(N + 1, 0);
  dp[0] = 1;
  const int MOD = 1e9 + 7;
  for (int i = 1; i <= N; ++i) {
    for (int curr = 1; curr <= 6 && (i - curr) >= 0; ++curr) {
      dp[i] += dp[i - curr];
      dp[i] %= MOD;
    }
  }

  cout << dp[N] << '\n';
}