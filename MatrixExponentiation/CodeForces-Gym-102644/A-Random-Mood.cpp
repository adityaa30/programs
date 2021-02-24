#include <bits/stdc++.h>
using namespace std;

struct Mat22 {
  double mat[2][2] = {{0.0, 0.0}, {0.0, 0.0}};
  Mat22() {}
  Mat22(double _00, double _01, double _10, double _11) {
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
          res.mat[i][j] += (mat[i][k] * m.mat[k][j]);
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
  Mat22 res(1.0, 0.0, 0.0, 1.0);
  while (y > 0) {
    if (y & 1)
      res = res * x;
    x = x * x;
    y /= 2;
  }
  return res;
}

int32_t main() {
  cout << fixed << setprecision(20);
  int n;
  double p;
  cin >> n >> p;

  Mat22 x(1 - p, p, p, 1 - p);
  Mat22 res = BinaryExp(x, n);
  cout << res.mat[0][0] << '\n';
  return 0;
}