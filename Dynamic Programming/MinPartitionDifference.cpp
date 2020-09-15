#include <bits/stdc++.h>
using namespace std;

int MinPartitionDifference(vector<int> vals) {
  const int N = vals.size();
  int sum = 0;
  for (int x : vals)
    sum += x;

  bool dp[N][sum + 1];
  int minDiff = sum;
  for (int S = 0; S <= sum; ++S) {
    for (int i = 0; i < N; ++i) {
      if (S == 0)
        dp[i][S] = true;
      else if (i == 0)
        dp[i][S] = (S == vals[i]);
      else {
        dp[i][S] = dp[i - 1][S];
        if (S - vals[i] > 0)
          dp[i][S] = dp[i][S] || dp[i - 1][S - vals[i]];
      }
      if (dp[i][S]) {
        minDiff = min(minDiff, abs(2 * S - sum));
      }
    }
  }
  return minDiff;
}

int32_t main() {
  cout << MinPartitionDifference({1, 6, 11, 5}) << '\n';      // 1
  cout << MinPartitionDifference({3, 1, 4, 2, 2, 1}) << '\n'; // 1
}