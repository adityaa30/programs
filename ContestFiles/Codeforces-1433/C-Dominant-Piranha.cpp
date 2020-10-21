#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) cin >> A[i];
  int mx = 0;
  bool equal = A[0] == A[n - 1];
  for (int i = 1; i < n - 1; ++i) {
    equal = equal && (A[i] == A[0]);
    if (A[i] >= A[mx] && (A[i] > A[i - 1] || A[i] > A[i + 1])) mx = i;
  }
  if (n >= 2 && A[n - 1] >= A[mx] && A[n - 1] > A[n - 2]) {
    mx = n - 1;
  }
  if (equal && n != 1) cout << "-1\n";
  else cout << (mx + 1) << '\n'; 
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