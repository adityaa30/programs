#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
  int n;
  cin >> n;
  vector<int> A(n);
  int mx = 0, s = 0;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    mx = max(mx, A[i]);
    s += A[i];
  }
  s += max(0LL, mx - (s - mx));
  cout << s << '\n';
  return 0;
}