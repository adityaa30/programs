// adityaa30
#include <bits/stdc++.h>
using namespace std;

template <class T> class LazySegmentTree {
  using QueryMergeType = function<T(T &, T &)>;
  using UpdateMergeType = function<T(T &, T &, int len)>;

  int size;
  T QueryNeutralVal, UpdateNeutralVal;
  /**
   * nodes -> store the values on which the SegmentTree is build,
   *  Eg, Min Segment Tree, nodes[x] = min over lx ... rx
   *
   * operations -> store the actual values
   */
  vector<T> nodes, operations;
  QueryMergeType QueryOp;
  UpdateMergeType UpdateOp;

public:
  /**
   * x -> Index in the nodes array (0-based indexing)
   * [lx, rx] -> Range covered by the x'th node in the original array ->
   *    nodes[x] = func(arr[lx, rx])
   * Child of x -> (2x + 1), (2x + 2)
   */

  void MergeChildNodes(int x) {
    /** Any associative operation can be used to merge here
     * x op y op z <=> (x op y) op z <=> x op (y op z)
     * Example: Matrix/Modular/Normal Multiply/Add, Bitwise Operations,
     *  GCD,
     */
    nodes[x] = QueryOp(nodes[2 * x + 1], nodes[2 * x + 2]);
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
    MergeChildNodes(x);
  }

  void Propagate(int x, int lx, int rx) {
    if (rx == lx) {
      // Left Node, we cannot propagate
      return;
    }

    // Apply operation to the children
    int m = lx + (rx - lx) / 2;

    // [lx .. m]
    operations[2 * x + 1] = UpdateOp(operations[2 * x + 1], operations[x], 1);
    nodes[2 * x + 1] = UpdateOp(nodes[2 * x + 1], operations[x], m - lx + 1);

    // [m+1 .. rx]
    operations[2 * x + 2] = UpdateOp(operations[2 * x + 2], operations[x], 1);
    nodes[2 * x + 2] =
        UpdateOp(nodes[2 * x + 2], operations[x], rx - (m + 1) + 1);

    operations[x] = UpdateNeutralVal;
  }

  void Update(int l, int r, T val, int x, int lx, int rx) {
    assert(lx <= rx);
    Propagate(x, lx, rx);
    if (r < lx || rx < l) {
      // [l...r lx...rx l...r]
      // Do not intersect
      return;
    } else if (l <= lx && rx <= r) {
      // [l .. lx...rx .. r]
      // Whole segment covered
      operations[x] = UpdateOp(operations[x], val, 1);
      nodes[x] = UpdateOp(nodes[x], val, rx - lx + 1);
      return;
    }

    int m = lx + (rx - lx) / 2;
    Update(l, r, val, 2 * x + 1, lx, m);
    Update(l, r, val, 2 * x + 2, m + 1, rx);
    MergeChildNodes(x);
  }

  T Query(int l, int r, int x, int lx, int rx) {
    assert(lx <= rx);
    Propagate(x, lx, rx);
    if (r < lx || rx < l) {
      // [l...r lx...rx l...r]
      // Do not intersect
      return QueryNeutralVal;
    } else if (l <= lx && rx <= r) {
      // [l .. lx...rx .. r]
      // Whole segment covered
      return nodes[x];
    }

    int m = lx + (rx - lx) / 2;
    T left = Query(l, r, 2 * x + 1, lx, m);
    T right = Query(l, r, 2 * x + 2, m + 1, rx);
    return QueryOp(left, right);
  }

public:
  LazySegmentTree(int n, T queryNeutralVal, QueryMergeType queryOp,
                  T updateNeutralVal, UpdateMergeType updateOp) {
    // Initialize empty segment tree
    size = 1;
    while (size < n) {
      size *= 2;
    }

    this->QueryNeutralVal = queryNeutralVal;
    this->QueryOp = queryOp;
    nodes.assign(2 * size, queryNeutralVal);

    this->UpdateNeutralVal = updateNeutralVal;
    this->UpdateOp = updateOp;
    operations.assign(2 * size, updateNeutralVal);
  }

  LazySegmentTree(vector<T> arr, T queryNeutralVal, QueryMergeType queryOp,
                  T updateNeutralVal, UpdateMergeType updateOp)
      : LazySegmentTree((int)arr.size(), queryNeutralVal, queryOp,
                        updateNeutralVal, updateOp) {
    Build(arr, 0, 0, size - 1);
  }

  void Update(int l, int r, T val) {
    assert(l < size);
    assert(r < size);
    assert(l <= r);
    Update(l, r, val, 0, 0, size - 1);
  }

  T Query(int l, int r) {
    assert(l <= r);
    return Query(l, r, 0, 0, size - 1);
  }

  T Query(int idx) { return Query(idx, idx); }

  T &operator[](const int idx) { return this->nodes[idx]; }

  int Size() { return size; }
};
