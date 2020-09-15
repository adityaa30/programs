// adityaa30
// Question: https://www.hackerrank.com/challenges/ctci-merge-sort/problem
#include <bits/stdc++.h>
using namespace std;
using li = int64_t;

struct FenwickTree {
  li size;
  li *table;

  FenwickTree(li size) {
    this->table = new li[size + 1];
    memset(this->table, 0, sizeof(this->table));
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

  li t;
  cin >> t;
  while (t--) {
    li n;
    cin >> n;
    li arr[n], ans = 0;

    for (li i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    // Coordinate Compression
    vector<li> temp(arr, arr + n);
    sort(temp.begin(), temp.end());
    for (li i = 0; i < n; ++i) {
      arr[i] = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin() + 1;
    }

    // Now only size of 10e5 is required due to coordinate compression
    FenwickTree ft(100005);
    for (li i = n - 1; i >= 0; --i) {
      ft.Update(arr[i], 1);
      ans += ft.Sum(arr[i] - 1);
    }

    cout << ans << '\n';
  }

  return 0;
}