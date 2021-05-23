// adityaa30
#include <bits/stdc++.h>
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
