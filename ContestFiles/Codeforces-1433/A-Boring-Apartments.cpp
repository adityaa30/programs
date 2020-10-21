#include <bits/stdc++.h>
#define int long long int
using namespace std;

void Solve() {
  string num;
  vector<int> sum {1, 3, 6, 10};
  cin >> num;
  int ans = 0;
  ans += (num[0] - '1') * sum.back();
  ans += sum[num.length() - 1];
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