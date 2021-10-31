#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  int ans = -1, low = 0, high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    cout << mid << ' ' << A[mid] << '\n'; 
    if (mid == A[mid]) {
      ans = mid;
      break;
    } else if (mid > A[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
