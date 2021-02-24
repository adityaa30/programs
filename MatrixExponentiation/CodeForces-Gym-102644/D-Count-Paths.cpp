#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;

struct Matrix {
  int size;
  vector<vector<int>> mat;
  Matrix(int sz) : size(sz) {
    mat = vector<vector<int>>(sz, vector<int>(sz, 0));
  }

  Matrix operator*(const Matrix &m) {
    Matrix res(size);
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        for (int k = 0; k < size; ++k) {
          res.mat[i][j] += (mat[i][k] * m.mat[k][j]) % MOD;
          res.mat[i][j] %= MOD;
        }
      }
    }
    return res;
  }
  friend ostream &operator<<(ostream &os, const Matrix &m) {
    for (int i = 0; i < m.size; ++i) {
      for (int j = 0; j < m.size; ++j) {
        os << m.mat[i][j] << ' ';
      }
      os << '\n';
    }
    return os;
  }
};

Matrix BinaryExp(Matrix x, int y) {
  Matrix res(x.size);
  for (int i = 0; i < x.size; ++i) {
    res.mat[i][i] = 1;
  }
  while (y > 0) {
    if (y & 1)
      res = res * x;
    x = x * x;
    y /= 2;
  }
  return res;
}

int32_t main() {
  int n, m, k;
  cin >> n >> m >> k;
  Matrix mat(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    mat.mat[u][v] = 1;
  }

  /*

  number of ways to reach 'u'
  new_dp[u] += 1 * dp[v] (for all possible v where v -> u edge exists)
  new_dp[u] += 0 * dp[v] (for all possible v where v -> u edge not exist)

  new_dp[u] -> number of paths to `u` after (k+1) steps
  dp[u] -> number of paths to `u` after k stepsb
  */

  Matrix res = BinaryExp(mat, k);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans += res.mat[i][j];
      ans %= MOD;
    }
  }
  cout << ans << '\n';

  return 0;
}