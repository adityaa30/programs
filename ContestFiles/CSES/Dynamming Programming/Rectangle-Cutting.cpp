#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
int32_t main() {
  int a, b;
  scanf("%d %d", &a, &b);

  vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));

  function<int(int, int)> calc = [&](int w, int h) {
    if (dp[w][h] != -1) return dp[w][h];
    if (w == h) return dp[w][h] = 0;
    if (w == 0 || h == 0) return dp[w][h] = 1;
    
    int res = INF;
    for (int i = 1; i < w; ++i) res = min(res, calc(i, h) + calc(w - i, h) + 1);
    for (int i = 1; i < h; ++i) res = min(res, calc(w, i) + calc(w, h - i) + 1);
    return dp[w][h] = res;
  };
  
  for (int w = 0; w <= a; ++w) {
    for (int h = 0; h <= b; ++h) {
      if (w == h) dp[w][h] = 0;
      else if (w == 0 || h == 0) dp[w][h] = 1;
      else {
        dp[w][h] = INF;
        for (int i = 1; i < w; ++i) dp[w][h] = min(dp[w][h], dp[i][h] + dp[w - i][h] + 1);
        for (int i = 1; i < h; ++i) dp[w][h] = min(dp[w][h], dp[w][i] + dp[w][h - i] + 1);
      }
    }
  }

  printf("%d", dp[a][b]);
}