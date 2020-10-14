#include <bits/stdc++.h>
using namespace std;

const int mxS = 100 * 1000;

int32_t main() {
  int n;
  scanf("%d", &n);
  int vals[n];
  for (int i = 0; i < n; ++i) scanf("%d", &vals[i]);
  bitset<mxS> dp;
  dp[0] = 1;
  for (int i = 0; i < n; ++i) dp = dp | (dp << vals[i]);

  printf("%d\n", dp.count() - 1);
  for (int i = 1; i < mxS; ++i)
    if (dp[i]) printf("%d ", i);

  return 0;
}