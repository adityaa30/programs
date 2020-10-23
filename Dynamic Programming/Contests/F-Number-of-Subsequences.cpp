// https://codeforces.com/contest/1426/problem/F
#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;

void Solve() {
  int N;
  cin >> N;
  string str;
  cin >> str;
  int dp[N + 1][3];
  int A = 0, AB = 1, ABC = 2;
  memset(dp, 0, sizeof(dp));
  int p3 = 1LL;
  for (int i = 1; i <= N; ++i) {
    dp[i][A] = dp[i - 1][A];
    dp[i][AB] = dp[i - 1][AB];
    dp[i][ABC] = dp[i - 1][ABC];
    if (str[i - 1] == '?') {
      // ..a? -> ..aa | ..ab | ..ac -> Same count tripled!
      dp[i][A] = 3 * dp[i - 1][A] + p3;                // tripled
      dp[i][AB] = 3 * dp[i - 1][AB] + dp[i - 1][A];    // tripled + ('?' -> b)
      dp[i][ABC] = 3 * dp[i - 1][ABC] + dp[i - 1][AB]; // tripled + ('?' -> c)
      p3 = p3 * 3;
    } else if (str[i - 1] == 'a') {
      dp[i][A] = dp[i - 1][A] + p3;
    } else if (str[i - 1] == 'b') {
      dp[i][AB] = dp[i - 1][AB] + dp[i - 1][A];
    } else if (str[i - 1] == 'c') {
      dp[i][ABC] = dp[i - 1][ABC] + dp[i - 1][AB];
    }
    p3 %= MOD;
    dp[i][A] %= MOD;
    dp[i][AB] %= MOD;
    dp[i][ABC] %= MOD;
  }

  cout << dp[N][ABC] << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);
  Solve();

  return 0;
}