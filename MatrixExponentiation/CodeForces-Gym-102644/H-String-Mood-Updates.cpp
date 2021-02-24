#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;
const int HAPPY = 0, SAD = 1;

template <class T> class SegmentTree {
  using MergeType = function<T(T &, T &)>;

  int size;
  T NeutralVal;
  vector<T> nodes;
  MergeType Merge;

public:
  /**
   * x -> Index in the nodes array (0-based indexing)
   * [lx, rx] -> Range covered by the x'th node in the original array ->
   *    nodes[x] = func(arr[lx, rx])
   * Child of x -> (2x + 1), (2x + 2)
   */

  void MergeChildsOfNode(int x) {
    /** Any associative operation can be used to merge here
     * x op y op z <=> (x op y) op z <=> x op (y op z)
     * Example: Matrix/Modular/Normal Multiply/Add, Bitwise Operations,
     *  GCD,
     */
    nodes[x] = Merge(nodes[2 * x + 1], nodes[2 * x + 2]);
  }

private:
  void Build(vector<T> &initial, int x, int lx, int rx) {
    if (rx == lx) {
      // Bottom layer (leaf)
      if (lx < (int)initial.size()) {
        nodes[x] = initial[lx];
      }
      return;
    }

    int m = lx + (rx - lx) / 2;
    Build(initial, 2 * x + 1, lx, m);
    Build(initial, 2 * x + 2, m + 1, rx);
    MergeChildsOfNode(x);
  }

  void Set(int idx, T val, int x, int lx, int rx) {
    assert(lx <= rx);
    if (rx == lx) {
      // Bottom layer (leaf)
      nodes[x] = val;
      return;
    }
    int m = lx + (rx - lx) / 2;
    if (idx <= m) {
      Set(idx, val, 2 * x + 1, lx, m);
    } else {
      Set(idx, val, 2 * x + 2, m + 1, rx);
    }
    MergeChildsOfNode(x);
  }

  T Query(int l, int r, int x, int lx, int rx) {
    if (r < lx || rx < l) {
      // [l...r lx...rx l...r]
      // Do not intersect
      return NeutralVal;
    } else if (l <= lx && rx <= r) {
      // [l .. lx...rx .. r]
      // Whole segment covered
      return nodes[x];
    }

    int m = lx + (rx - lx) / 2;
    T left = Query(l, r, 2 * x + 1, lx, m);
    T right = Query(l, r, 2 * x + 2, m + 1, rx);
    return Merge(left, right);
  }

public:
  SegmentTree(int n, T neutralVal, MergeType merge) {
    // Initialize empty segment tree
    size = 1;
    while (size < n)
      size *= 2;
    nodes.assign(2 * size, neutralVal);

    this->NeutralVal = neutralVal;
    this->Merge = merge;
  }

  SegmentTree(vector<T> arr, T neutralVal, MergeType merge)
      : SegmentTree((int)arr.size(), neutralVal, merge) {
    Build(arr, 0, 0, size - 1);
  }

  void Set(int idx, T val) {
    assert(idx < size);
    Set(idx, val, 0, 0, size - 1);
  }

  T Query(int l, int r) {
    assert(l <= r);
    return Query(l, r, 0, 0, size - 1);
  }
  T Query(int idx) { return Query(idx, idx); }

  T &operator[](const int idx) { return this->nodes[idx]; }

  int Size() { return size; }
};

struct Mat22 {
public:
  array<array<int, 2>, 2> mat;
  Mat22() {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        mat[i][j] = 0;
      }
    }
  }
  Mat22(int _00, int _01, int _10, int _11) {
    mat[0][0] = _00;
    mat[0][1] = _01;
    mat[1][0] = _10;
    mat[1][1] = _11;
  }
  Mat22(char match) {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        mat[i][j] = 0;
      }
    }

    // mat[mood-1][mood-2] -> number of ways to place a character instead of '?'
    // incase of character != '?' value is either 0 or 1
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
      if (match == '?' || match == ch) {
        if (ch == 'S' || ch == 'D') {
          // Always makes him sad
          ++mat[HAPPY][SAD];
          ++mat[SAD][SAD];
        } else if (ch == 'H') {
          // Always makes him happy
          ++mat[HAPPY][HAPPY];
          ++mat[SAD][HAPPY];
        } else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' ||
                   ch == 'U') {
          // Flips the mood
          ++mat[HAPPY][SAD];
          ++mat[SAD][HAPPY];
        } else {
          // Nothing happens to the mood
          ++mat[HAPPY][HAPPY];
          ++mat[SAD][SAD];
        }
      }
    }
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

int32_t main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  vector<Mat22> init(n);
  for (int i = 0; i < n; ++i) {
    init[i] = Mat22(s[i]);
  }

  Mat22 identity(1, 0, 0, 1);
  SegmentTree<Mat22> st(init, identity,
                        [](Mat22 &a, Mat22 &b) { return a * b; });

  for (int rep = 0; rep < q; ++rep) {
    cout << st.Query(0, n - 1).mat[HAPPY][HAPPY] << '\n';
    int x;
    char c;
    cin >> x >> c;
    st.Set(x - 1, Mat22(c));
  }
  cout << st.Query(0, n - 1).mat[HAPPY][HAPPY] << '\n';

  return 0;
}