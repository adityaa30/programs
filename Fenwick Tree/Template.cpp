#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
class FenwickTree {
  int size;
  vector<int> table;

public:
  FenwickTree(int size) : size(size) { this->table = vector<int>(size + 5, 0); }

  void Update(int idx, int delta) {
    delta %= MOD;
    for (; idx <= this->size; idx += (idx & (-idx))) {
      table[idx] += delta;
      table[idx] %= MOD;
    }
  }

  int Sum(int idx) {
    int res = 0;
    for (; idx > 0; idx -= (idx & (-idx))) {
      res += table[idx];
      res %= MOD;
    }
    return res % MOD;
  }

  int RangeSum(int l, int r) {
    int to = Sum(r);
    int from = Sum(l - 1);
    int ans = to - from;
    ans %= MOD;
    if (ans < 0) {
      ans += MOD;
    }
    return ans;
  }

  int operator[](int idx) { return RangeSum(idx, idx); }
};

int main() {}