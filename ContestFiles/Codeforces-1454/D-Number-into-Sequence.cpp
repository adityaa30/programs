#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve() {
  int n;
  cin >> n;
  vector<int> facs;
  for (int i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      facs.push_back(i);
      n /= i;
    }
  }
  if (n > 1) {
    facs.push_back(n);
  }
  sort(facs.begin(), facs.end());
 
  map<int, int> cnt;
  int sz = 0;
  for (int x : facs) {
    cnt[x]++;
    sz = max(cnt[x], sz);
  }
  vector<int> ans(sz, 1);
  for (auto [x, count] : cnt) {
    for (int i = sz - 1, j = count; i >= 0 && j > 0; --i, --j) {
      ans[i] *= x;
    }
  } cout << ans.size() << '\n';
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