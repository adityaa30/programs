#include <bits/stdc++.h>
using namespace std;

int BiggestIndexSmallerThan(int x, vector<int> &A) {
  int low = 0, high = A.size() - 1;
  int idx = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (A[mid] > x) {
      high = mid - 1;
      idx = mid;
    } else if (A[mid] <= x) {
      low = mid + 1;
    }
  }
  return idx;
}

int32_t main() {
  int n, x;
  cin >> n;
  vector<int> towers;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    int idx = BiggestIndexSmallerThan(x, towers);
    if (idx == -1) {
      towers.push_back(x);
    } else {
      towers[idx] = x;
    }
  }
  cout << towers.size() << '\n';
  return 0;
}