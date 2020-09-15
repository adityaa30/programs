// adityaa30
#include <bits/stdc++.h>
#define li long long int
using namespace std;

struct FenwickTree {
  li size;
  vector<li> table;

  FenwickTree(li size) {
    this->table = vector<li>(size + 1, 0);
    this->size = size;
  }

  // Update position i by delta
  void Update(li i, li delta) {
    while (i <= size) {
      table[i] += delta;
      i += i & (-i);
    }
  }

  // Compute the prefix sum value [1, i]
  li Sum(li i) {
    li sum = 0;
    while (i > 0) {
      sum += table[i];
      i -= i & (-i); // i &= (i - 1);
    }
    return sum;
  }

  li RangeSum(li l, li r) { return Sum(r) - Sum(l - 1); }

  li operator[](li n) { return this->table[n]; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  li n, q, c, a, b, temp;
  n = 5;
  FenwickTree ft(n);

  for (li i = 1; i <= n; ++i) {
    ft.Update(i, 1);
  }

  for (li i = 0; i <= n; ++i) {
    cout << ft.RangeSum(i, i) << ' ';
  }
  cout << '\n';
  ft.Update(3, 20);
  ft.Update(1, -20);
  for (li i = 0; i <= n; ++i) {
    cout << ft.RangeSum(i, i) << ' ';
  }
  cout << '\n';
  return 0;
}