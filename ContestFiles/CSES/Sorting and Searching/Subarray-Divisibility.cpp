#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int mxN = 2e5 + 1;

int32_t main() {
  int n, x;
  cin >> n;

  int count[mxN];
  memset(count, 0, sizeof(count));

  count[0] = 1;
  int ans = 0, prefix = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    prefix = (prefix + x) % n;
    if (prefix < 0) prefix += n;
    ans += count[prefix];
    ++count[prefix];
  }
  cout << ans << '\n';

  return 0;
}