#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;

int32_t main() {
  int N;
  cin >> N;
  vector<string> mat(N);
  for (int i = 0; i < N; ++i) {
    cin >> mat[i];
  }
  int dp[N][N];
  dp[0][0] = (mat[0][0] != '*');
  for (int i = 1; i < N; ++i) {
    dp[i][0] = (mat[i][0] == '*' ? 0 : dp[i - 1][0]);
    dp[0][i] = (mat[0][i] == '*' ? 0 : dp[0][i - 1]);
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < N; ++j) {
      if (mat[i][j] == '*') {
        dp[i][j] = 0;
      } else {
        dp[i][j] = (dp[i - 1][j] % MOD) + (dp[i][j - 1] % MOD);
        dp[i][j] %= MOD;
      }
    }
  }

  cout << dp[N - 1][N - 1] << '\n';

  return 0;
}