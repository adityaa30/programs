#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int INF = LLONG_MAX;
const int mxN = 71;

int dp[mxN][mxN][mxN][mxN];

void Solve() {
  int n, m, k;
  scanf("%lld %lld %lld", &n, &m, &k);
  vector<vector<int>> mat(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%lld", &mat[i][j]);
    }
  }
  if (m <= 1) {
    printf("0\n");
    return;
  }

  memset(dp, -1, sizeof(dp));
  int mxCnt = m / 2;
  function<int(int, int, int, int)> solve = [&](int r, int c, int rem, int cnt) {
    if (dp[r][c][rem][cnt] != -1) return dp[r][c][rem][cnt];
    if (cnt > mxCnt) return -INF;
    if (r == 0) {
      if (rem == 0) return 0LL;
      else return -INF;
    }
    if (c == 0) return solve(r - 1, m, rem, 0);
    int ans = mat[r - 1][c - 1] + solve(r, c - 1, (rem + mat[r - 1][c - 1]) % k, cnt + 1);
    ans = max(ans, solve(r, c - 1, rem, cnt));
    return dp[r][c][rem][cnt] = ans;
  };
  solve(n, m, 0, 0);
  printf("%lld\n", dp[n][m][0][0]);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);
  Solve();

  return 0;
}