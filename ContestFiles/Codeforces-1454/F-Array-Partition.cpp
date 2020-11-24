#include <bits/stdc++.h>
#define int long long int
using namespace std;

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

void Solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  unordered_map<int, vector<int>> idx;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    idx[A[i]].push_back(i);
  }
  vector<int> sufMx = A;
  for (int i = n - 2; i >= 0; --i)
    sufMx[i] = max(sufMx[i], sufMx[i + 1]);
  SegmentTree<int> st(A, INT_MAX, [](int a, int b) { return min(a, b); });

  int mx = A[0];
  for (int i = 0; i < n - 2; ++i) {
    mx = max(A[i], mx);
    vector<int> idxs = idx[mx];
    auto up = upper_bound(idxs.begin(), idxs.end(), i);
    if (up == idxs.end()) continue;
    int j = idxs[up - idxs.begin()];
    assert(A[j] == mx);
    if (j == n - 1) continue;
    // find k in [j + 1, n - 1] s.t sufMx[k] = mx
    int low = j + 1, high = n - 1;
    int k = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (sufMx[mid] == mx) {
        k = mid;
        high = mid - 1;
      } else if (sufMx[mid] > mx) {
        low = mid + 1;
      } else if (sufMx[mid] < mx) {
        high = mid - 1;
      }
    }
    if (k == -1) continue;
    int mn = st.Query(i + 1, k - 1);
    if (mn == mx) {
      int x = i + 1;
      int y = (k - 1) - (i + 1) + 1;
      int z = (n - 1) - k + 1;
      cout << "YES\n" << x << ' ' << y << ' ' << z << '\n';
      return;
    }
 }

  cout << "NO\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  int t = 1;
  cin >> t;
  for (int test = 1; test <= t; ++test) {
    // cout << "Case #" << test << ": ";
    Solve();
  }

  return 0;
}