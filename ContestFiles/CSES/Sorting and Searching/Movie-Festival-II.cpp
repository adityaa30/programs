#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int n, k;
  cin >> n >> k;

  vector<array<int, 2>> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i][0] >> A[i][1];
  }
  sort(A.begin(), A.end(), [](array<int, 2> &x, array<int, 2> &y) {
    if (x[1] == y[1])
      return x[0] > y[0];
    return x[1] < y[1];
  });

  multiset<int> times;
  int count = 0;
  for (int i = 0; i < n; ++i) {
    auto it = times.upper_bound(A[i][0]);
    if (it != times.begin() && !times.empty()) {
      --it;
      times.erase(it);
      times.insert(A[i][1]);
      ++count;
    } else if ((int) times.size() < k) {
      times.insert(A[i][1]);
      ++count;
    }
  }

  cout << count << '\n';

  return 0;
}