#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve() {
  int n;
  cin >> n;
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[i] = i + 1;
  }
  for (int i = 0; i < n/2; ++i) {
    swap(ans[i], ans[n - i - 1]);
  }

  if (n & 1) {
    swap(ans[0], ans[n/2]);
  }

  for (int x : ans) {
    cout << x << ' ';
  }
  cout << '\n';

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