#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) cin >> A[i];
  vector<int> B(m);
  for (int i = 0; i < m; ++i) cin >> B[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int count = 0;
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (B[j] + k < A[i]) ++j;
    else if (B[j] - k > A[i]) ++i;
    else {
      ++count, ++i, ++j;
    }
  }
  cout << count << '\n';
  return 0;
}