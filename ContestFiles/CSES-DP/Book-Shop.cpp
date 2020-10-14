#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int n, x;
  scanf("%d %d", &n, &x);
  int price[n], pages[n];
  for (int i = 0; i < n; ++i)
    scanf("%d", &price[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &pages[i]);

  int dp[x + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    for (int j = x; j >= price[i]; --j) {
      dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
    }
  }

  printf("%d", dp[x]);
}