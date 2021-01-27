#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int INF = 1e18 + 3;

int32_t main() {
  int n, t;
  cin >> n >> t;
  vector<int> A(n);

  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }

  int low = 1, high = *min_element(A.begin(), A.end()) * t;
  int ans = high;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int total = 0;
    for (int x : A) total += mid / x;
    if (total >= t) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}