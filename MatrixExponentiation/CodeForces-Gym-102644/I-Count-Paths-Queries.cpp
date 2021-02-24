#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_BITS = 30;

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

int32_t main() {
  int n, m, q;
  cin >> n >> m >> q;
  Matrix mat(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    ++mat.mat[u][v];
  }

  /*
  number of ways to reach 'u'
  new_dp[u] += 1 * dp[v] (for all possible v where v -> u edge exists)
  new_dp[u] += 0 * dp[v] (for all possible v where v -> u edge not exist)

  new_dp[u] -> number of paths to `u` after (k+1) steps
  dp[u] -> number of paths to `u` after k stepsb
  */

  vector<Matrix> p2(MAX_BITS, Matrix(n));
  p2[0] = mat;
  for (int i = 1; i < MAX_BITS; ++i) {
    p2[i] = p2[i - 1] * p2[i - 1];
  }

  for (int rep = 0; rep < q; ++rep) {
    int s, t, k;
    cin >> s >> t >> k;
    --s, --t;
    vector<int> dp(n);
    ++dp[s];

    for (int bit = 0; bit < MAX_BITS; ++bit) {
      if ((1LL << bit) & k) {
        vector<int> new_dp(n);
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            new_dp[j] += (p2[bit].mat[i][j] * dp[i]) % MOD;
            new_dp[j] %= MOD;
          }
        }
        dp = new_dp;
      }
    }

    cout << dp[t] << '\n';
  }

  return 0;
}