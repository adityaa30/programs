#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) cin >> A[i];
  sort(A.begin(), A.end());
  int m = A[n/2];
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += abs(A[i] - m);
  }
  cout << ans << '\n';
  return 0;
}