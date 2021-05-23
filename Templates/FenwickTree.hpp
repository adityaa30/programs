#pragma once
#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
  int size;
  vector<int> table;
  FenwickTree(int size) : size(size) { this->table = vector<int>(size + 5, 0); }

  void Update(int idx, int delta) {
    for (; idx < this->size; idx += (idx & (-idx))) {
      table[idx] += delta;
    }
  }

  int Sum(int idx) {
    int res = 0;
    for (; idx > 0; idx -= (idx & (-idx))) {
      res += table[idx];
    }
    return res;
  }

  int RangeSum(int l, int r) { return this->Sum(r + 1) - this->Sum(l); }
  int operator[](int idx) { return this->RangeSum(idx, idx); }
};
