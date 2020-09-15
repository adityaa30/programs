#include <bits/stdc++.h>
#define int long long int
using namespace std;

int MinCostPath(vector<vector<int>> cost) {
  int N = cost.size(), M = cost[0].size();
  int dp[N][M];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = cost[0][0];

  for (int i = 1; i < N; ++i) dp[i][0] = dp[i - 1][0] + cost[i][0];
  for (int j = 1; j < M; ++j) dp[0][j] = dp[0][j - 1] + cost[0][j];

  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < M; ++j) {
      int from = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
      dp[i][j] = cost[i][j] + from;
    }
  }

  cout << "Min Cost Matrix: \n";
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << dp[i][j] << '\t';
    }
    cout << "\n";
  }

  return dp[N - 1][M - 1];
}

int32_t main() {
  int cost = MinCostPath({{1, 2, 3}, {4, 8, 2}, {1, 5, 3}});
  cout << "MinCost = " << cost;

  return 0;
}