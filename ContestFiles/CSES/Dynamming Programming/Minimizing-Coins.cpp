#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
  int N, X;
  cin >> N >> X;
  vector<int> c(N);
  for (int i = 0; i < N; ++i)
    cin >> c[i];

  int dp[X + 1];
  dp[0] = 0;
  for (int money = 1; money <= X; ++money) {
    dp[money] = INT_MAX;
    for (int i = 0; i < N; ++i) {
      if ((money - c[i]) >= 0)
        dp[money] = min(dp[money], 1 + dp[money - c[i]]);
        
    }
  }
  cout << (dp[X] == INT_MAX ? -1 : dp[X]) << '\n';
}