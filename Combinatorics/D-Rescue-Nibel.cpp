// https://codeforces.com/contest/1420/problem/D
#include <bits/stdc++.h>
#define var(x) #x, x
#define int long long int
using namespace std;

const int MOD = 998244353;
const int mxN = 1e6 + 5;

vector<int> fac(mxN, 1);

int power(int x, int y) {
  int res = 1;
  x %= MOD;
  while (y > 0) {
    if (y & 1)
      res = (res * x) % MOD;
    y = y >> 1;
    x = (x * x) % MOD;
  }
  return res % MOD;
}

void Precompute() {
  for (int i = 1; i < fac.size(); ++i) {
    fac[i] = fac[i - 1] * i;
    fac[i] %= MOD;
  }
}

int inverse(int x) { return power(x, MOD - 2) % MOD; }

int nCk(int n, int k) {
  if (k < 0 || k > n)
    return 0;

  if (n == 0 || k == 0)
    return 1;
  int res = fac[n];
  res = (res * inverse(fac[k]));
  res %= MOD;
  res = (res * inverse(fac[n - k]));
  res %= MOD;
  return res;
}

void Solve(int test) {
  int N, K;
  cin >> N >> K;
  vector<pair<int, int>> arr;
  for (int i = 0; i < N; ++i) {
    int l, r;
    cin >> l >> r;
    arr.push_back({l, 1});
    arr.push_back({r + 1, -1});
  }
  sort(arr.begin(), arr.end());
  int ans = 0, curr = 0;
  for (pair<int, int> pi : arr) {
    if (pi.second == 1) {
      // Take this segment for sure + choose (K - 1) remaining  
      ans += nCk(curr, K - 1);
      ans %= MOD;
      ++curr;
      continue;
    }
    --curr;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);
  Precompute();
  Solve(0);
  return 0;
}