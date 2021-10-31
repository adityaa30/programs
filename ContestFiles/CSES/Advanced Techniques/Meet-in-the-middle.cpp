#include <bits/stdc++.h>
#define int long long int
using namespace std;
 
void Solve(int test) {
  int n, x;
  cin >> n >> x;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
 
  map<int, int> dp;
  int sz = min((n + 1) / 2, 20LL);
  int L = 1LL << sz;
  for (int mask = 0; mask < L; ++mask) {
    int s = 0;
    for (int bit = 0; bit < sz; ++bit) {
      if ((1LL << bit) & mask) {
        s += A[bit];
      }
    }
    if (s <= x) {
      dp[s]++;
    }
  }
 
  for (int i = 0, j = sz; i < sz && j < n; ++i, ++j) {
    A[i] = A[j];
  }
  A.resize(n - sz);
  sz = n - sz;
  L = 1LL << sz;
  int ans = 0;
  for (int mask = 0; mask < L; ++mask) {
    int s = 0;
    for (int bit = 0; bit < sz; ++bit) {
      if ((1LL << bit) & mask) {
        s += A[bit];
      }
    }
    if (s <= x && dp.find(x - s) != dp.end()) {
      ans += dp[x - s];
    }
  }
 
  cout << ans << '\n';
}
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);
 
  int t = 1;
  // cin >> t;
  for (int test = 1; test <= t; ++test) {
    // cout << "Case #" << test << ": ";
    Solve(test);
  }
 
  return 0;
}
