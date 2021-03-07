// https://binarysearch.com/problems/Fractional-Knapsack
#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int INF = 3e14;

int solve(vector<int> &weights, vector<int> &values, int capacity) {
  int n = values.size();
  // -INF as we are calculating for exact `w`
  vector<pair<double, int>> _values(n);
  for (int i = 0; i < n; ++i) {
    _values[i] = {values[i] / (weights[i] + 0.0), weights[i]};
  }
  sort(_values.rbegin(), _values.rend());

  double ans = 0;
  int left = capacity;
  for (int i = 0; i < n && left > 0; ++i) {
    int take = min(left, _values[i].second);
    ans += _values[i].first * take;
    left -= take;
  }

  return (int)ans;
}

int32_t main() { return 0; }
