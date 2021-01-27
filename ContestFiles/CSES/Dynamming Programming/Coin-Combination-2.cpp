#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;

int32_t main() {
  int N, X;
  cin >> N >> X;
  vector<int> c(N);
  for (int i = 0; i < N; ++i)
    cin >> c[i];

  int dp[X + 1];
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  
  // dp[money] == Number of ways to get X amount using only first i coins
  for (int i = 0; i < N; ++i) {
    for (int money = c[i]; money <= X; ++money) {
      dp[money] += dp[money - c[i]];
      dp[money] %= MOD;
    }
  }
  cout << dp[X] << '\n';
  return 0;
}