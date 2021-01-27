#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int n;
  scanf("%d", &n);
  map<int, int> compress;
  int from[n], to[n], price[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d", &from[i], &to[i], &price[i]);
    compress[from[i]] = 0;
    compress[to[i]] = 0;
  }
  
  int coord = 0;
  for (auto &p : compress) p.second = ++coord;

  vector<vector<array<int, 2>>> projects(coord + 1);
  for (int i = 0; i < n; ++i) {
    projects[compress[to[i]]].push_back({compress[from[i]], price[i]});
  }

  long long int dp[coord + 1];
  memset(dp, 0LL, sizeof(dp));
  for (int i = 1; i <= coord; ++i) {
    dp[i] = dp[i - 1];
    for (auto &p : projects[i]) dp[i] = max(dp[i], dp[p[0] - 1] + p[1]);
  }
  printf("%lld", dp[coord]);

  return 0;
}