#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int n, x;
  scanf("%d", &n);
  vector<int> dp;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    auto it = lower_bound(dp.begin(), dp.end(), x);
    if (it == dp.end()) {
      dp.push_back(x);
    } else {
      *it = x;
    }
  }
  printf("%d", (int)dp.size());
  return 0;
}