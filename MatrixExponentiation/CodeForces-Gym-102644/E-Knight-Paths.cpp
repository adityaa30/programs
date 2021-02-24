#include <bits/stdc++.h>
using namespace std;

const int BOARD_SIZE = 8;

template <typename T> struct Matrix {
  int size;
  vector<vector<T>> mat;
  Matrix(int sz) : size(sz) {
    mat = vector<vector<T>>(sz, vector<T>(sz));
  }

  Matrix operator*(Matrix &m) {
    Matrix res(size);
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        for (int k = 0; k < size; ++k) {
          res[i][j] += (mat[i][k] * m[k][j]);
        }
      }
    }
    return res;
  }

  vector<T> &operator[](const int idx) { return mat[idx]; }
};

Matrix<unsigned int> BinaryExp(Matrix<unsigned int> x, int y) {
  Matrix<unsigned int> res(x.size);
  for (int i = 0; i < x.size; ++i) {
    res[i][i] = 1;
  }
  while (y > 0) {
    if (y & 1)
      res = res * x;
    x = x * x;
    y /= 2;
  }
  return res;
}

const vector<int> delta = {1, -1, 2, -2};

bool InsideBoard(int x, int y) { return (0 <= x && x < BOARD_SIZE && 0 <= y && y < BOARD_SIZE); }

int32_t main() {
  int k;
  cin >> k;
  Matrix<unsigned int> mat(BOARD_SIZE * BOARD_SIZE + 1);
  for (int col = 0; col < BOARD_SIZE; ++col) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
      for (int dx : delta) {
        for (int dy : delta) {
          const int nRow = row + dx, nCol = col + dy;
          if (abs(dx) == abs(dy) || !InsideBoard(nRow, nCol))
            continue;
          // denotes an extra edge (+= optional as no multi-edges)
          mat[row * BOARD_SIZE + col][nRow * BOARD_SIZE + nCol] = 1;
        }
      }
      mat[row * BOARD_SIZE + col][BOARD_SIZE * BOARD_SIZE] = 1; // taking sum of count to paths for each (row, col)
    }
  }
  mat[BOARD_SIZE * BOARD_SIZE][BOARD_SIZE * BOARD_SIZE] = 1; // taking sum of all transitions

  auto res = BinaryExp(mat, k + 1);
  cout << res[0][64] << '\n';
  return 0;
}