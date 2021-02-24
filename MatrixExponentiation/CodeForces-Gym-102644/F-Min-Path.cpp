#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int INF = LLONG_MAX;

struct Matrix {
  int size;
  vector<vector<int>> mat;
  Matrix(int sz) : size(sz) {
    mat = vector<vector<int>>(sz, vector<int>(sz, INF));
  }

  Matrix operator*(Matrix &m) {
    assert(m.size == size);
    Matrix res(size);
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        for (int k = 0; k < size; ++k) {
          if (mat[i][k] == INF || m[k][j] == INF) continue;
          res[i][j] = min(res[i][j], mat[i][k] + m[k][j]);
        }
      }
    }
    return res;
  }

  vector<int> &operator[](const int idx) { return mat[idx]; }
};

Matrix BinaryExp(Matrix x, int y) {
  Matrix res(x.size);
  for (int i = 0; i < res.size; ++i) {
    res[i][i] = 0;
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

  for (int e = 0; e < m; ++e) {
    int u, v, c;
    cin >> u >> v >> c;
    --u, --v;
    mat[u][v] = c;
  }

  /*

  for min path to vertex u
  new_dp[u] = min(new_dp[u], dp[v] + c); for all v
  c => u -> v edge weight
  */

  auto res = BinaryExp(mat, k);
  int ans = INF;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans = min(ans, res[i][j]);
    }
  }
  if (ans == INF) {
    cout << "IMPOSSIBLE\n";
  } else {
    cout << ans << '\n';
  }

  return 0;
}