#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
  int N, X;
  cin >> N >> X;
  vector<int> c(N);
  for (int i = 0; i < N; ++i)
    cin >> c[i];

  const int MOD = 1e9 + 7;

  int dp[X + 1];
  dp[0] = 1;
  for (int money = 1; money <= X; ++money) {
    dp[money] = 0;
    for (int i = 0; i < N; ++i) {
      if ((money - c[i]) >= 0)
        dp[money] += dp[money - c[i]];
      dp[money] %= MOD;
    }
  }
  cout << dp[X] << '\n';
}