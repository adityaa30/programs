// adityaa30
// Leetcode - Count of Smaller Numbers
// Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
  int size;
  vector<int> table;
  FenwickTree(int size) : size(size) { this->table = vector<int>(size + 5, 0); }

  void Update(int idx, int delta) {
    for (; idx < this->size; idx += (idx & (-idx)))
      table[idx] += delta;
  }

  int Sum(int idx) {
    int res = 0;
    for (; idx > 0; idx -= (idx & (-idx)))
      res += table[idx];
    return res;
  }

  int RangeSum(int l, int r) { return this->Sum(r + 1) - this->Sum(l); }
  int operator[](int idx) { return this->RangeSum(idx, idx); }
};

class Solution {
public:
  vector<int> countSmaller(vector<int> nums) {
    const int N = nums.size();

    // Coordinate Compress
    vector<pair<int, int>> coord(N);
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
      coord[i] = {nums[i], i};
    sort(coord.begin(), coord.end());
    int idx = 1, c = 1;
    if (N > 0)
      arr[coord[0].second] = 1;
    for (int i = 1; i < N; ++i) {
      if (coord[i - 1].first != coord[i].first)
        c += 1;
      arr[coord[i].second] = c;
    }

    vector<int> ans(N);
    FenwickTree ft(N + 1);

    for (int i = N - 1; i >= 0; --i) {
      ans[i] = ft.Sum(arr[i] - 1);
      ft.Update(arr[i], 1);
    }
    return ans;
  }
};

int32_t main() {
  Solution s;
  vector<int> ans = s.countSmaller({5, 2, 6, 1});
  // 2, 1, 1, 0
  for (int x : ans)
    cout << x << ' ';
  cout << '\n';
}