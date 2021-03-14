// adityaa30
#include <bits/stdc++.h>
using namespace std;

template <class T> class SegmentTree {
  using MergeType = function<T(T &, T &)>;

  int size;
  T NeutralVal;
  vector<T> operations;
  MergeType Merge;

public:
  /**
   * x -> Index in the operations array (0-based indexing)
   * [lx, rx] -> Range covered by the x'th node in the original array ->
   *    operations[x] = func(arr[lx, rx])
   * Child of x -> (2x + 1), (2x + 2)
   */

private:
  void Update(int l, int r, T val, int x, int lx, int rx) {
    assert(lx <= rx);
    if (r < lx || rx < l) {
      // [l...r lx...rx l...r]
      // Do not intersect
      return;
    } else if (l <= lx && rx <= r) {
      // [l .. lx...rx .. r]
      // Whole segment covered
      operations[x] = Merge(operations[x], val);
      return;
    }

    int m = lx + (rx - lx) / 2;
    Update(l, r, val, 2 * x + 1, lx, m);
    Update(l, r, val, 2 * x + 2, m + 1, rx);
  }

  T Query(int idx, int x, int lx, int rx) {
    assert(lx <= rx);
    if (rx == lx) {
      // Bottom layer (leaf)
      return operations[x];
    }

    int m = lx + (rx - lx) / 2;
    T ans;
    if (idx <= m) {
      ans = Query(idx, 2 * x + 1, lx, m);
    } else {
      ans = Query(idx, 2 * x + 2, m + 1, rx);
    }

    return Merge(ans, operations[x]);
  }

public:
  SegmentTree(int n, T neutralVal, MergeType merge) {
    // Initialize empty segment tree
    size = 1;
    while (size < n)
      size *= 2;
    operations.assign(2 * size, neutralVal);

    this->NeutralVal = neutralVal;
    this->Merge = merge;
  }

  void Update(int l, int r, T val) {
    assert(l < size);
    assert(r < size);
    assert(l <= r);
    Update(l, r, val, 0, 0, size - 1);
  }

  T Query(int idx) {
    assert(idx < size);
    return Query(idx, 0, 0, size - 1);
  }

  T &operator[](const int idx) { return this->operations[idx]; }

  int Size() { return size; }
};