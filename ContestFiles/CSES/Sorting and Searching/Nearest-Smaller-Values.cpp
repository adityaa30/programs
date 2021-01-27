#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int &a : A) cin >> a;

  stack<int> s;
  vector<int> ans(n);

  for (int i = n - 1; i >= 0; --i) {
    while (!s.empty() && A[s.top()] > A[i]) {
      ans[s.top()] = i + 1;
      s.pop();
    }
    s.push(i);
  }

  for (int x : ans) cout << x << ' ';
  cout << '\n';

  return 0;
}