#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
  int n;
  cin >> n;
  vector<array<int, 2>> A(n);
  for (int i = 0; i < n; ++i) cin >> A[i][0] >> A[i][1];
  sort(A.begin(), A.end());
  int ans = 0, t = 0;
  for (int i = 0; i < n; ++i) {
    t += A[i][0];
    ans += A[i][1] - t;
  }
  cout << ans << '\n';
  return 0;
}