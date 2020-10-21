#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) cin >> A[i];
  int start = -1, end = -1;
  for (int i = 0; i < n; ++i) {
    if (A[i] == 1) {
      start = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (A[i] == 1) {
      end = i;
      break;
    }
  }
  int ans = 0;
  for (int i = start; i <= end; ++i) {
    if (A[i] == 0) ++ans;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  int t = 1;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
    // cout << "Case #" << test << ": ";
    Solve();
  }

  return 0;
}