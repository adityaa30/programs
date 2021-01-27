#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) cin >> A[i];
  sort(A.begin(), A.end());
  int sz = unique(A.begin(), A.end()) - A.begin();
  cout << sz << '\n';
  return 0;
}