#include <bits/stdc++.h>
using namespace std;

bool PossiblePartion(vector<int> vals) {
  const int N = vals.size();
  int sum = 0;
  for (int x : vals)
    sum += x;
  if (sum & 1)
    return false;

  bool dp[N][(sum / 2) + 1];
  for (int S = 0; S <= (sum / 2); ++S) {
    for (int i = 0; i < N; ++i) {
      if (S == 0)
        dp[i][S] = true;
      else if (i == 0)
        dp[i][S] = (S == vals[i]);
      else {
        dp[i][S] = dp[i - 1][S];
        if (S - vals[i] >= 0) {
          dp[i][S] = dp[i][S] || dp[i - 1][S - vals[i]];
        }
      }
    }
  }
  return dp[N - 1][sum / 2];
}

int32_t main() {
  cout << PossiblePartion({3, 1, 1, 2, 2, 1}) << '\n'; // True
  cout << PossiblePartion({1, 5, 11, 5}) << '\n';      // True
  cout << PossiblePartion({1, 5, 2}) << '\n';          // False
}