#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;

template <typename T> struct Matrix {
  int size;
  vector<vector<T>> mat;
  Matrix(int sz) : size(sz) { mat = vector<vector<T>>(sz, vector<T>(sz)); }

  Matrix operator*(Matrix &m) {
    Matrix res(size);
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        for (int k = 0; k < size; ++k) {
          res[i][j] += (mat[i][k] * m[k][j]) % MOD;
          res[i][j] %= MOD;
        }
      }
    }
    return res;
  }

  vector<T> &operator[](const int idx) { return mat[idx]; }
};

Matrix<int> BinaryExp(Matrix<int> x, int y) {
  Matrix<int> res(x.size);
  for (int i = 0; i < x.size; ++i) res[i][i] = 1;
  while (y > 0) {
    if (y & 1) {
      res = res * x;
    }
    x = x * x;
    y /= 2;
  }
  return res;
}

int32_t main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n), C(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> C[i];
  }

  int p, q, r;
  cin >> p >> q >> r;

  /*
  vector<int> dp(n + 3);
  for (int i = 0; i < n; ++i) {
    dp[i] = A[i];
  }
  dp[n] = 1;         // 1
  dp[n + 1] = n;     // i
  dp[n + 2] = n * n; // i * i

  for (int rep = 0; rep < k - n + 1; ++rep) {
    vector<int> new_dp(n + 3);

    // new_dp[n - 1] = p + q * i + r * i * i;
    new_dp[n] = dp[n];
    new_dp[n - 1] += p * dp[n];

    new_dp[n + 1] = dp[n + 1] + dp[n]; // (i+1) = (i) + (1)
    new_dp[n - 1] += q * dp[n + 1];

    // (i+1)^2 = (i * i) + (2 * i) + (1)
    new_dp[n + 2] = dp[n + 2] + 2 * dp[n + 1] + dp[n];
    new_dp[n - 1] += r * dp[n + 2];

    for (int j = 0; j < n; ++j) {
      new_dp[n - 1] += C[j] * dp[n - 1 - j];
    }

    for (int i = 0; i < n - 1; ++i) {
      new_dp[i] = dp[i + 1];
    }

    dp = new_dp;
  }
  */

  Matrix<int> coeff(n + 3);
  coeff[n][n] += 1;
  coeff[n][n - 1] += p;

  coeff[n][n + 1] += 1;
  coeff[n + 1][n + 1] += 1;
  coeff[n + 1][n - 1] += q;

  coeff[n + 2][n + 2] += 1;
  coeff[n + 1][n + 2] += 2;
  coeff[n][n + 2] += 1;
  coeff[n + 2][n - 1] = r;

  for (int j = 0; j < n; ++j) {
    coeff[n - 1 - j][n - 1] = C[j];
  }

  for (int i = 0; i < n - 1; ++i) {
    coeff[i + 1][i] = 1;
  }

  auto factor = BinaryExp(coeff, k - n + 1);
  vector<int> dp(n + 3), new_dp(n + 3);

  for (int i = 0; i < n; ++i) dp[i] = A[i];
  dp[n] = 1, dp[n + 1] = n, dp[n + 2] = n * n;

  for (int i = 0; i < n + 3; ++i) {
    for (int j = 0; j < n + 3; ++j) {
      new_dp[j] += (dp[i] * factor[i][j]) % MOD;
      new_dp[j] %= MOD;
    }
  }

  cout << new_dp[n - 1] << '\n';
};