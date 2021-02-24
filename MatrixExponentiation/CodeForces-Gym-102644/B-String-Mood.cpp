#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;

struct Mat22 {
  int mat[2][2] = {{0, 0}, {0, 0}};
  Mat22() {}
  Mat22(int _00, int _01, int _10, int _11) {
    mat[0][0] = _00;
    mat[0][1] = _01;
    mat[1][0] = _10;
    mat[1][1] = _11;
  }

  Mat22 operator*(const Mat22 &m) {
    Mat22 res;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          res.mat[i][j] += (mat[i][k] * m.mat[k][j]) % MOD;
          res.mat[i][j] %= MOD;
        }
      }
    }
    return res;
  }

  friend ostream &operator<<(ostream &os, const Mat22 &m) {
    os << m.mat[0][0] << ' ' << m.mat[0][1] << '\n';
    os << m.mat[1][0] << ' ' << m.mat[1][1] << '\n';
    return os;
  }
};

Mat22 BinaryExp(Mat22 x, int y) {
  Mat22 res(1, 0, 0, 1); // (H -> H, H -> S, S -> H, S -> S) {H: HAPPY, S: SAD}
  while (y > 0) {
    if (y & 1)
      res = res * x;
    x = x * x;
    y /= 2;
  }
  return res;
}

int32_t main() {
  int n;
  cin >> n;

  /*
  new_dp[HAPPY] = 19 * dp[HAPPY] + 6 * dp[SAD]
  new_dp[SAD] = 7 * dp[HAPPY] + 20 * dp[SAD]

  Trick: Find each state ({HAPPY, SAD}) in terms of other states ({HAPPY, SAD}) for previous minute. 

  new_dp[HAPPY] += 19 * dp[HAPPY];
  new_dp[SAD] += 7 * dp[HAPPY];

  new_dp[HAPPY] += 6 * dp[SAD];
  new_dp[SAD] += 20 * dp[SAD];

  dp = new_dp;

  If the transition can be written like:
    new_dp[j] += dp[i] * m[i][j]; (m -> multiplier) (for all i)
  we can tranform to exponentiation.
  */

  Mat22 x(19, 7, 6, 20);
  Mat22 res = BinaryExp(x, n);
  cout << res.mat[0][0] << '\n';
  return 0;
}