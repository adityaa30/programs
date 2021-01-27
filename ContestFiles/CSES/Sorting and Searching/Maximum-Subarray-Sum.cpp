#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
  int n, x;
  cin >> n;
  int ans = INT_MIN, curr = INT_MIN;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    curr = max(x, curr + x);
    ans = max(ans, curr);
  }
  cout << ans << '\n';
  return 0;
}