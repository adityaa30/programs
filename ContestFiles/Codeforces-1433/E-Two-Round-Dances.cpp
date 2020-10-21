#include <bits/stdc++.h>
#define int long long int
using namespace std;

int binomialCoeff(int n, int k) {
  int C[n + 1][k + 1];
  int i, j;

  // Caculate value of Binomial Coefficient
  // in bottom up manner
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= min(i, k); j++) {
      // Base Cases
      if (j == 0 || j == i)
        C[i][j] = 1;

      // Calculate value using previously
      // stored values
      else
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }

  return C[n][k];
}

void Solve() {
  int n;
  cin >> n;
  int ans = binomialCoeff(n, n / 2);
  int fac = 1;
  n /= 2;
  for (int i = 1; i <= (n - 1); ++i) {
    fac *= i;
  }
  fac *= fac;
  ans *= fac;
  cout << ans / 2 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);
  Solve();
  return 0;
}