#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int mxA = 1e9 + 1;

int32_t main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  
  int mx = 0, total = 0;
  for (int &a : A) {
    cin >> a;
    mx = max(mx, a);
    total += a;
  }

  auto Check = [&](int limit) {
    int count = 1, prefix = 0;
    for (int i = 0; i < n; ++i) {
      prefix += A[i];
      if (prefix > limit) {
        prefix = A[i];
        ++count;
      }
    }
    return count <= k;
  };

  int low = mx, high = total;
  int ans = total;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (Check(mid)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout << ans << '\n';

  return 0;
}