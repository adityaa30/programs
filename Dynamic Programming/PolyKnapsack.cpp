// https://binarysearch.com/problems/Poly-Knapsack
#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int INF = 3e14;

int solve(vector<int> &weights, vector<int> &values, int capacity) {
  int n = values.size();
  // -INF as we are calculating for exact `w`
  vector<int> dp(capacity + 1, -INF);
  dp[0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int w = 0; w <= capacity; ++w) {
      if (w >= weights[i]) {
        dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
      }
    }
  }

  return *max_element(dp.begin(), dp.end());
}

int32_t main() { return 0; }
