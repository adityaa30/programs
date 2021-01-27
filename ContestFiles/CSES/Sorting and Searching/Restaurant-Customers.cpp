#include <bits/stdc++.h>
using namespace std;

const int ENTER = 0, EXIT = 1;

int32_t main() {
  int n;
  cin >> n;
  vector<array<int, 2>> T;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    T.push_back({a, ENTER});
    T.push_back({b, EXIT});
  }

  sort(T.begin(), T.end());

  int curr = 0, mx = 0;
  for (auto [_, t] : T) {
    if (t == ENTER) ++curr;
    else --curr;
    mx = max(mx, curr);
  }
  cout << mx << '\n';
  return 0;
}