#include <bits/stdc++.h>
using namespace std;


int32_t main() {
  int n;
  cin >> n;
  vector<array<int, 2>> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i][0] >> A[i][1];
  }
  sort(A.begin(), A.end(), [](array<int, 2> a, array<int, 2> b) {
    if (a[1] == b[1]) {
      return a[0] < b[0];
    }
    return a[1] < b[1];
  });
  int count = 0, prev = 0;
  for (int i = 0; i < n; ++i) {
    if (A[i][0] >= prev) {
      ++count;
      prev = A[i][1];
    }
  }

  cout << count << '\n';
  return 0;
}