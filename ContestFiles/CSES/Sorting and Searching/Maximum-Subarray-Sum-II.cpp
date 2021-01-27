#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int INF = 1e18 + 3;

int32_t main() {
  int n, a, b, x;
  cin >> n >> a >> b;

  vector<int> prefix(n);
  vector<int> minUpto(n);
  deque<int> dq;

  for (int i = 0; i < n; ++i) {
    cin >> x;
    prefix[i] = x + (i ? prefix[i - 1] : 0LL);
  }

  int windowSize = b - a + 1;

  for (int i = 0; i < n; ++i) {
    while (!dq.empty() && prefix[dq.back()] > prefix[i]) dq.pop_back();
    while (!dq.empty() && (i - dq.front() + 1) > windowSize) dq.pop_front();
    dq.push_back(i);
    minUpto[i] = dq.front();
  }

  int ans = prefix[a - 1];
  for (int i = a; i < b; ++i) {
    int mn = min(0LL, prefix[minUpto[i - a]]);
    ans = max(ans, prefix[i] - mn);
  }

  for (int i = b; i < n; ++i) {
    int mn = prefix[minUpto[i - a]];
    ans = max(ans, prefix[i] - mn);
  }
  cout << ans << '\n';

  return 0;
}