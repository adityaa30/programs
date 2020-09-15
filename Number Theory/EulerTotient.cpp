/* Problem D : Same GCD's
 * https://codeforces.com/contest/1295/problem/D */

// adityaa30
#include <bits/stdc++.h>
#define int long long int
#define debug(a) cout << #a << "=" << a << ' ';
using namespace std;

const int MOD = 1000000007;

// Euler's Totient
int phi(int n) {
  int ans = n;
  for (int p = 2; p * p <= n; ++p) {
    if (n % p == 0) {
      ans -= ans / p;
      while (n % p == 0)
        n /= p;
    }
  }
  if (n > 1) {
    ans -= ans / n;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
    int a, m;
    cin >> a >> m;
    int gcd = __gcd(a, m);
    cout << phi(m / gcd) << '\n';
  }

  return 0;
}